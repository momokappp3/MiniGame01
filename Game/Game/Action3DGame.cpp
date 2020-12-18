#include "Action3DGame.h"

Action3DGame::Action3DGame() {

	_pCamera = nullptr;
	_pModel = nullptr;
	_pAnimation = nullptr;
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

	_pCamera->SetPosition(0.0f,10.0f,-20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);


	return true;
}

bool Action3DGame::Process() {

	/*
	
	移動の処理など
	*/





	return true;
}

bool Action3DGame::Render() {
	return true;
}

bool Action3DGame::Terminate() {
	return true;
}