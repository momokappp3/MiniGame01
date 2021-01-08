#include "GalGame.h"

GalGame::GalGame() {

	_pCamera = nullptr;
	_pCharaModel = nullptr;
	_pMouseInput = nullptr;
	_pNovelBG = nullptr;
	_pAnimationBase = nullptr;
	//_pAnimation = nullptr;
}

GalGame::~GalGame() {
}

bool GalGame::Initialize() {

	if (!ModeBase::Initialize()) {
		return false;
	}

	//メモリの所有権を委ねるには.reset
	_pCamera.reset(new Camera);
	//_pCharaModel.reset(new Model);
	_pRoomModel.reset(new Model);
	_pMouseInput.reset(new MouseInput);
	_pNovelBG.reset(new NovelBG);
	_pAnimationBase.reset(new AnimationBase);


	if (!_pNovelBG->Initialize()) {
		return false;
	}


	_pCamera->SetPosition(0.0f, 10.0f, -20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);

	_pAnimationBase->Load("model/onna/onna.pmx");
	_pRoomModel->Load("model/room/roomkagu.pmx");

	return true;
}

bool GalGame::Process() {

	if (_pMouseInput == nullptr) {
		return false;
	}

	if (CheckHitKey(KEY_INPUT_A)) {

		//モデルに対して角度をつけ足せる
		_pAnimationBase->GetTransform().AddRotateY(5.0f);
	}

	if (CheckHitKey(KEY_INPUT_S)) {

		//モデルに対して角度をつけ足せる
		_pAnimationBase->GetTransform().AddRotateY(-5.0f);
	}

	if (CheckHitKey(KEY_INPUT_D)) {
		_pAnimationBase->Play(true, 1, 5.0f);
		_pNovelBG->SetCommentFlag(true);
	}

	_pAnimationBase->Process();
	_pCamera->Process();
	_pRoomModel->Process();
	_pMouseInput->Process();
	_pNovelBG->Process();

	return true;
}

bool GalGame::Render() {

	_pCamera->Render();
	_pAnimationBase->Render();
	_pRoomModel->Render();
	_pMouseInput->Draw();
	_pNovelBG->Draw();

	return true;
}

bool GalGame::Terminate() {
	return true;
}