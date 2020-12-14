#include "Action3DGame.h"

Action3DGame::Action3DGame() {
	_pmxModelHandle = -1;

	_pCamera = nullptr;
}

Action3DGame::~Action3DGame() {
}

bool Action3DGame::Initialize() {

	if (!ModeBase::Initialize()) {
		return false;
	}

	//ƒƒ‚ƒŠ‚ÌŠ—LŒ ‚ðˆÏ‚Ë‚é‚É‚Í.reset
	_pCamera.reset(new Camera);

	_pCamera->SetPosition(0.0f,10.0f,-20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);

	//_attachIndex = MV1AttachAnim(_cg, 0, -1, FALSE);

	//_totalTime = MV1GetAttachAnimTotalTime(_cg, _attachIndex);

	//_playTime = 0.0f;

	return true;
}

bool Action3DGame::Process() {
	return true;
}

bool Action3DGame::Render() {
	return true;
}

bool Action3DGame::Terminate() {
	return true;
}