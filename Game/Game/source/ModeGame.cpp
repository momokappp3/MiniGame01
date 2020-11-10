#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeGame.h"

bool ModeGame::Initialize() {

	if (!base::Initialize()) {
		return false; 
	}

	_cg = MV1LoadModel("model/rori.pmx");
	_x = 0;
	_y = 0;

	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���(�J�����̏����ʒu)
	SetCameraNearFar(0.1f, 800.0f);

	//(0,10,-20)�̎��_����(0,10,0)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));

	return true;
}

bool ModeGame::Terminate() {
	base::Terminate();
	return true;
}

bool ModeGame::Process() {
	base::Process();
	int key = ApplicationMain::GetInstance()->GetKey();

	if (key & PAD_INPUT_LEFT)	{ _x -= 8; }
	if (key & PAD_INPUT_RIGHT)	{ _x += 8; }
	if (key & PAD_INPUT_UP)		{ _y -= 8; }
	if (key & PAD_INPUT_DOWN)	{ _y += 8; }


	//test

	return true;
}

bool ModeGame::Render() {
	base::Render();

	MV1DrawModel(_cg);

	return true;
}

