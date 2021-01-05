#include "GalGame.h"

GalGame::GalGame() {

	_pCamera = nullptr;
	_pCharaModel = nullptr;
	_pMouseInput = nullptr;
	//_pAnimation = nullptr;
}

GalGame::~GalGame() {
}

bool GalGame::Initialize() {

	if (!ModeBase::Initialize()) {
		return false;
	}

	//�������̏��L�����ς˂�ɂ�.reset
	_pCamera.reset(new Camera);
	_pCharaModel.reset(new Model);
	_pRoomModel.reset(new Model);
	_pMouseInput.reset(new MouseInput);

	_pCamera->SetPosition(0.0f, 10.0f, -20.0f);
	_pCamera->SetTarget(0.0f, 10.0f, 0.0f);
	_pCamera->SetNearFar(0.1f, 800.0f);

	_pCharaModel->Load("model/onna/onna.pmx");
	_pRoomModel->Load("model/room/roomkagu.pmx");

	return true;
}

bool GalGame::Process() {

	if (_pMouseInput == nullptr) {
		return false;
	}

	if (CheckHitKey(KEY_INPUT_A)) {

		//���f���ɑ΂��Ċp�x����������
		_pCharaModel->GetTransform().AddRotateY(5.0f);
	}

	if (CheckHitKey(KEY_INPUT_S)) {

		//���f���ɑ΂��Ċp�x����������
		_pCharaModel->GetTransform().AddRotateY(-5.0f);
	}

	_pCharaModel->Process();
	_pCamera->Process();
	_pRoomModel->Process();
	_pMouseInput->Process();

	return true;
}

bool GalGame::Render() {

	_pCamera->Render();
	_pCharaModel->Render();
	_pRoomModel->Render();
	_pMouseInput->Draw();
	return true;
}

bool GalGame::Terminate() {
	return true;
}