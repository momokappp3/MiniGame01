#include "../Mode/GalGame.h"
#include <string>

GalGame::GalGame() {

	_pCamera = nullptr;
	_pCharaModel = nullptr;
	_pMouseInput = nullptr;
	_pAnimationBase = nullptr;
	_pSelectComment = nullptr;
	_pScriptEngin = nullptr;
	_pSoundManager = nullptr;

	_favor = 0;
}

GalGame::~GalGame() {
}

bool GalGame::Initialize() {

	if (!ModeBase::Initialize()) {
		return false;
	}

	//�������̏��L�����ς˂�ɂ�.reset
	_pCamera.reset(new Camera);
	//_pCharaModel.reset(new Model);
	_pRoomModel.reset(new Model);
	_pMouseInput.reset(new MouseInput);
	_pAnimationBase.reset(new AnimationBase);
	_pSelectComment.reset(new SelectComment);
	_pScriptEngin.reset(new amg::ScriptEngine);
	_pSoundManager.reset(new SoundManager);

	if (!_pSelectComment->Initialize()){
		return false;
	}

	if (!_pScriptEngin->Initialize("source/excel/escape_from_amg1.json")) {
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

	_favor = _pScriptEngin->GetFavor();

	if (CheckHitKey(KEY_INPUT_A)) {

		//���f���ɑ΂��Ċp�x����������
		_pAnimationBase->GetTransform().AddRotateY(5.0f);
	}

	if (CheckHitKey(KEY_INPUT_S)) {

		//���f���ɑ΂��Ċp�x����������
		_pAnimationBase->GetTransform().AddRotateY(-5.0f);
	}

	if (CheckHitKey(KEY_INPUT_D)) {
		_pAnimationBase->Play(true, 1, 5.0f);
	}

	if (CheckHitKey(KEY_INPUT_G)) {

		//�r������J�n
		_pScriptEngin->SetState(amg::ScriptEngine::ScriptState::PARSING);

	}

	std::string str(_T("��������������"));

	//��x�ϐ��Ɏ���Ă���֐��ɓn��
	_pSelectComment->SetString(str);

	_pAnimationBase->Process();
	_pCamera->Process();
	_pRoomModel->Process();
	_pMouseInput->Process();
	_pSelectComment->Process();
	_pScriptEngin->Update();

	return true;
}

bool GalGame::Render() {

	_pCamera->Render();
	_pAnimationBase->Render();
	_pRoomModel->Render();
	_pMouseInput->Draw();
	_pSelectComment->Draw();


	if (_pScriptEngin->GetState()!= amg::ScriptEngine::ScriptState::END) {
		_pScriptEngin->Render();
	}

	//debug���

	DrawFormatString(100, 900, GetColor(255, 0, 0), "�D���x%d",_favor);

	return true;
}

bool GalGame::Terminate() {

	_pScriptEngin->Destroy();
	return true;
}