#include "AnimationBase.h"

AnimationBase::AnimationBase() {
	_animationNum = -1;
	_playIndex = -1;

	_blendIndex = -1;
	_blendFrame = 0;
	_blendCount = 0;
}

AnimationBase::~AnimationBase() {
}

bool AnimationBase::Load(const TCHAR* fileName) {

	if (!Model::Load(fileName)) {
		return false;
	}

	_animationNum = MV1GetAnimNum(_handle);

	if (_animationNum == -1) {
		return false;
	}

	for (int i = 0; i < _animationNum; i++) {
		_mapAnimationTime.emplace(i, MV1GetAnimTotalTime(_handle, i));
	}

	return _animationNum != -1;
}

void AnimationBase::Process() {

	ProcessBlend();
	Model::Process();
}

void AnimationBase::ProcessBlend() {

	if (_playIndex >= 0 && _blendIndex >= 0 && _blendFrame > 0) {
		float rate = static_cast<float>(_blendCount) / static_cast<float>(_blendFrame);

		MV1SetAttachAnimBlendRate(_handle, _playIndex, 1.0f - rate);
		MV1SetAttachAnimBlendRate(_handle, _blendIndex, rate);

		if (_blendCount >= _blendFrame) {

			Detach(_playIndex);

			_playIndex = _blendIndex;
			_blendIndex = -1;
			_blendFrame = 0;
			_blendCount = 0;
		}
		else {
			_blendCount++;
		}
	}
}

bool AnimationBase::Play(int index, int blendFrame) {

	if (_animationNum == -1 || index < 0 || blendFrame < 0) {
		return false;
	}

	// �����C���f�b�N�X���u�����g���͏������Ȃ�
	if (_playIndex == index || _blendIndex >= 0) {
		return false;
	}

	if (_playIndex < 0) { // ���ݍĐ����Ă���A�j���[�V����������

		return ImmediatePlay(index);
	}
	else { // �Đ����̃A�j���[�V����������
		
		if (blendFrame == 0) { // �u�����h�t���[���w�肪 0 �Ȃ瑦���؂�ւ�

			Detach(_playIndex);

			return ImmediatePlay(index);
		}
		else { // �u�����h�t���[���w�肪����

			if (!Attach(index)) {
				return false;
			}

			_blendIndex = index;
			_blendFrame = blendFrame;
			_blendCount = 0;

			return true;
		}
	}
}

// �A�^�b�`��ɑ��Đ�
bool AnimationBase::ImmediatePlay(int index) {

	if (!Attach(index)) {
		return false;
	}

	_playIndex = index;

	return MV1SetAttachAnimTime(_handle, index, GetTime(index)) != -1;
}

void AnimationBase::Stop() {

	if (_playIndex >= 0) {

		Detach(_playIndex);

		_playIndex = -1;
	}

	if (_blendIndex >= 0) {

		Detach(_blendIndex);

		_blendIndex = -1;
		_blendFrame = 0;
		_blendCount = 0;
	}
}

bool AnimationBase::Attach(int index) {

	if (_animationNum == -1) {
		return false;
	}

	if (MV1AttachAnim(_handle, index) == -1) {
		return false;
	}

	return true;
}

bool AnimationBase::Detach(int index) {

	if (_animationNum == -1) {
		return false;
	}

	return MV1DetachAnim(_handle, index) != -1;
}

float AnimationBase::GetTime(int index) {
	auto count = _mapAnimationTime.count(index);

	if (count == 0) {
		return 0.0f;
	}

	return _mapAnimationTime[index];
}