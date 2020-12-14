#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeGame.h"

bool ModeGame::Initialize() {

	if (!base::Initialize()) {
		return false; 
	}

	_cg = MV1LoadModel("model/rori.pmx");
	//_back = MV1LoadModel("back/back2.x");
	_back = MV1LoadModel("back/backsakura.x");

	_x = 0;
	_y = 0;

	_near = 0.1f;
	_far = 800.0f;

	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���(�J�����̏����ʒu)
	SetCameraNearFar(0.1f, 800.0f);

	//(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));

	_attachIndex = MV1AttachAnim(_cg, 3, -1, FALSE);

	_totalTime = MV1GetAttachAnimTotalTime(_cg, _attachIndex);

	_playTime = 0.0f;

	return true;
}

bool ModeGame::Terminate() {
	base::Terminate();
	return true;
}

bool ModeGame::Process() {
	base::Process();

	int key = ApplicationMain::GetInstance()->GetKey();


	/*======================================
	�A�j��
	=======================================*/

	// �Đ����Ԃ�i�߂�
	_playTime += 0.2f;

	// �Đ����Ԃ��A�j���[�V�����̑��Đ����ԂɒB������Đ����Ԃ��O�ɖ߂�
	if (_playTime >= _totalTime) {
		_playTime = 0.0f;
	}
	// �Đ����Ԃ��Z�b�g����
	MV1SetAttachAnimTime(_cg, _attachIndex, _playTime);

	if (key & PAD_INPUT_RIGHT)	{ _x += 8; }
	if (key & PAD_INPUT_UP)		{
	
		_near += 0.5f;
		_y -= 8;
	}
	if (key & PAD_INPUT_DOWN)	{ 
		_near -= 0.5f;
		_y += 8; 
	}

	SetCameraNearFar(_near, _far);

	return true;
}

bool ModeGame::Render() {
	base::Render();

	MV1DrawModel(_cg);
	MV1DrawModel(_back);

	return true;
}

