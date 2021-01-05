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
		DrawString(20, 50, "マウス左ボタンが押されています", GetColor(255, 255, 255));
	}

	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0) {
		DrawString(20, 80, "マウス右ボタンが押されています", GetColor(255, 255, 255));
	}
}

void MouseInput::Draw() {
	DrawFormatString(20, 20, GetColor(255,255,255), "マウスの座標( %d, %d )", _posX, _posY);
}
