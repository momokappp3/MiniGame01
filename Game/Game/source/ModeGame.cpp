
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeGame.h"

bool ModeGame::Initialize() {
	if (!base::Initialize()) { return false; }

	_cg = LoadGraph("res/player00.png");
	_x = 0;
	_y = 0;

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

	return true;
}

bool ModeGame::Render() {
	base::Render();

	DrawGraph(_x, _y, _cg, TRUE);

	return true;
}

