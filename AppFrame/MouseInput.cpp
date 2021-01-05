#include "MouseInput.h"
#include "DxLib.h"

MouseInput::MouseInput() {
	SetMouseDispFlag(TRUE);

	_posX = 0;
	_posY = 0;
}

MouseInput::~MouseInput() {
}

void MouseInput::Process(){
	
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
		DrawString(20, 50, "�}�E�X���{�^����������Ă��܂�", GetColor(255, 255, 255));
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		DrawString(20, 80, "�}�E�X�E�{�^����������Ă��܂�", GetColor(255, 255, 255));
	}
}

void MouseInput::Draw() {
	DrawFormatString(20, 20, GetColor(255,255,255), "�}�E�X�̍��W( %d, %d )", _posX, _posY);
}
