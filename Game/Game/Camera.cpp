/*
�J��������
*/
#include "Camera.h"
#include "source/ApplicationMain.h"

Camera::Camera() {  //0������

	_vPos = VGet(0.0f, 0.0f, 0.0f);
	_vTarget = VGet(-12.230986f, 59.101776f, -15.002045f);
	_clipNear = 0.0f;
	_clipFar = 0.0f;

}

Camera::~Camera() {
}

void Camera::Process() {

	// �p�x�ύX
// Y����]
	float sx = _vPos.x - _vTarget.x;
	float sz = _vPos.z - _vTarget.z;
	//��y�̒����ƕ�x�̒�����atan2()�֐��ɗ^���邱�ƂŁA�p�x�Ƃ����W�A���P�ʂƂ��ċ��܂�
	float rad = atan2(sz, sx);
	//���� x �̔񕉂̕�������Ԃ��B
	float length = sqrt(sz * sz + sx * sx);

	int key = ApplicationMain::GetInstance()->GetKey();

	if (key & PAD_INPUT_LEFT) { rad -= 0.05f; }
	if (key & PAD_INPUT_RIGHT) { rad += 0.05f; }
	_vPos.x = _vTarget.x + cos(rad) * length;  //�J�����̉�]
	_vPos.z = _vTarget.z + sin(rad) * length;

	// Y�ʒu
	if (key & PAD_INPUT_DOWN) { 
		_vPos.y -= 5.f; 
	}
	if (key & PAD_INPUT_UP) { 
		_vPos.y += 5.f; 
	}

}

void Camera::Render() {

	/*
	�J���������������Ȃ������鎞
	*/

	// 3D��{�ݒ�
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	SetUseBackCulling(TRUE);

	// �J�����ݒ�X�V
	SetCameraPositionAndTarget_UpVecY(_vPos, _vTarget);
	SetCameraNearFar(_clipNear,_clipFar);


	//�J�����\��

	/*
	int x = 0, y = 0, size = 16;

	SetFontSize(size);
	DrawFormatString(x, y, GetColor(255, 0, 0), "Camera:"); y += size;
	DrawFormatString(x, y, GetColor(255, 0, 0), "  target = (%5.2f, %5.2f, %5.2f)",_vTarget.x, _vTarget.y,_vTarget.z); y += size;
	DrawFormatString(x, y, GetColor(255, 0, 0), "  pos    = (%5.2f, %5.2f, %5.2f)",_vPos.x, _vPos.y, _vPos.z); y += size;

	float sx = _vPos.x - _vTarget.x;
	float sz = _vPos.z - _vTarget.z;
	float length = sqrt(sz * sz + sx * sx);
	float rad = atan2(sz, sx);
	float deg = RAD2DEG(rad);

	DrawFormatString(x, y, GetColor(255, 0, 0), "  len = %5.2f, rad = %5.2f, deg = %5.2f", length, rad, deg); y += size;
	*/

}


