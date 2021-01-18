#include "../Mode/ModeTitleMenu.h"
#include "AppFrame.h"
#include "../ApplicationMain.h"
#include "../Mode/ModeTitle.h"
#include "ModeGame.h"
#include "../Mode/Action3DGame.h"
#include "../../../../AppFrame/Fade.h"
#include "../../ResourceServer.h"

bool ModeTitle::Initialize() {
	if (!ModeBase::Initialize()) {
		return false; 
	}

	_pInput.reset(new Input);

	_backHandle = ResourceServer::LoadGraph(_T("res/title.png"));
	_key = 0;

	return true;
}

bool ModeTitle::Process() {
	ModeBase::Process();

	if (_pInput != nullptr) {
		_pInput->Process();
	}

	if (_pInput->_key[KEY_INPUT_RETURN]==1) {
		ModeServer::GetInstance()->Del(this);  // ���̃��[�h���폜�\��
		ModeServer::GetInstance()->Add(new ModeTitleMenu(), 1, "ModeaTitleMenu");  // ���̃��[�h��o�^
	}

	return true;
}

bool ModeTitle::Render() {
	ModeBase::Render();

	DrawGraph(0, 0, _backHandle, TRUE);

	return true;
}

bool ModeTitle::Terminate() {
	// _cg ��������Ȃ��Ƃ����Ȃ����ǁAAMLib�͌ʉ���ł��Ȃ��E�E
	ModeBase::Terminate();

	return true;
}

