#include "Action3DGame.h"

Action3DGame::Action3DGame() {

	_pCamera = nullptr;
	_pModel = nullptr;
	//_pAnimation = nullptr;
}

Action3DGame::~Action3DGame() {
}

bool Action3DGame::Initialize() {

	/*
	最初の状態の初期化
	*/



	if (!ModeBase::Initialize()) {
		return false;
	}

	//メモリの所有権を委ねるには.reset
	_pCamera.reset(new Camera);
	_pModel.reset(new Model);

	_pCamera->SetPosition(0.0f,10.0f,-20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);

	_pModel->Load("model/otoko/otoko.pmx");

	return true;
}

bool Action3DGame::Process() {

	/*
	
	移動の処理など
	*/

	if (CheckHitKey(KEY_INPUT_A)) {

		//モデルに対して角度をつけ足せる
		_pModel->GetTransform().AddRotateY(5.0f);
	}

	if (CheckHitKey(KEY_INPUT_S)) {

		//モデルに対して角度をつけ足せる
		_pModel->GetTransform().AddRotateY(-5.0f);
	}

	_pModel->Process();
	_pCamera->Process();

	return true;
}

bool Action3DGame::Render() {

	_pCamera->Render();
	_pModel->Render();
	return true;
}

bool Action3DGame::Terminate() {
	return true;
}