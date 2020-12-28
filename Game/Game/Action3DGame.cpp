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
	_pModel.reset(new Model);

	_pCamera->SetPosition(0.0f,10.0f,-20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);

	_pModel->Load("model/otoko/otoko.pmx");

	return true;
}

bool Action3DGame::Process() {

	/*
	
	�ړ��̏����Ȃ�
	*/

	if (CheckHitKey(KEY_INPUT_A)) {

		//���f���ɑ΂��Ċp�x����������
		_pModel->GetTransform().AddRotateY(5.0f);
	}

	if (CheckHitKey(KEY_INPUT_S)) {

		//���f���ɑ΂��Ċp�x����������
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