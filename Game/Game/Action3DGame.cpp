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
	�ŏ��̏�Ԃ̏�����
	*/



	if (!ModeBase::Initialize()) {
		return false;
	}

	//�������̏��L�����ς˂�ɂ�.reset
	_pCamera.reset(new Camera);

	_pCamera->SetPosition(0.0f,10.0f,-20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);


	return true;
}

bool Action3DGame::Process() {

	/*
	
	�ړ��̏����Ȃ�
	*/





	return true;
}

bool Action3DGame::Render() {
	return true;
}

bool Action3DGame::Terminate() {
	return true;
}