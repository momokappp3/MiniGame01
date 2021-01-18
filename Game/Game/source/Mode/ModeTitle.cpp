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
		ModeServer::GetInstance()->Del(this);  // このモードを削除予約
		ModeServer::GetInstance()->Add(new ModeTitleMenu(), 1, "ModeaTitleMenu");  // 次のモードを登録
	}

	return true;
}

bool ModeTitle::Render() {
	ModeBase::Render();

	DrawGraph(0, 0, _backHandle, TRUE);

	return true;
}

bool ModeTitle::Terminate() {
	// _cg を解放しないといけないけど、AMLibは個別解放できない・・
	ModeBase::Terminate();

	return true;
}

