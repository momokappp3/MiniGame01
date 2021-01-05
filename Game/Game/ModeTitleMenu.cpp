#include "AppFrame.h"
#include "source/ApplicationMain.h"
#include "ModeTitleMenu.h"
//#include "ModeGame.h"
#include "Action3DGame.h"
#include "ResourceServer.h"
#include "GalGame.h"

ModeTitleMenu::ModeTitleMenu() {

	_pInput = nullptr;
	_menuKind = Kind::Max;

	_enterInput = 0;

	_x = 0;
	_y = 0;

	_backHandle = -1;
	_targetHandle = -1;

}

ModeTitleMenu::~ModeTitleMenu() {
}

bool ModeTitleMenu::Initialize() {
	if (!ModeBase::Initialize()) {
		return false;
	}

	_pInput.reset(new Input);

	_menuKind = Kind::NewGame;

	_x = 200;
	_y = 600;

	_backHandle = ResourceServer::LoadGraph(_T("res/menu.png"));
	_targetHandle = ResourceServer::LoadGraph(_T("res/target.png"));

	return true;
}

bool ModeTitleMenu::Process() {
	ModeBase::Process();

	if (_pInput != nullptr) {
		_pInput->Process();
	}


	if (_pInput->_key[(KEY_INPUT_UP)] == 1 && _menuKind < Kind::NewGame) {
		if (_menuKind == Kind::NewGame) {
			int now = static_cast<int>(_menuKind);

			now--;
			_x += 50;

			_menuKind = static_cast<Kind>(now);
		}
	}

	if (_pInput->_key[(KEY_INPUT_DOWN)]&& _menuKind > Kind::End) {
		if (_menuKind == Kind::NewGame) {
			int now = static_cast<int>(_menuKind);

			now--;
			_x -= -50;

			_menuKind = static_cast<Kind>(now);
		}
	}

	if (_pInput->_key[(KEY_INPUT_S)] ==1) {
		if (_menuKind == Kind::NewGame) {
			ModeServer::GetInstance()->Del(this);  // このモードを削除予約
			ModeServer::GetInstance()->Add(new Action3DGame(), 2, "Action3DGame");  // 次のモードを登録
		}

		if (_menuKind == Kind::End) {
			return false;
		}
	}

	if (_pInput->_key[(KEY_INPUT_A)] == 1) {
		if (_menuKind == Kind::NewGame) {
			ModeServer::GetInstance()->Del(this);  // このモードを削除予約
			ModeServer::GetInstance()->Add(new GalGame(), 3, "GalGame");  // 次のモードを登録
		}

		if (_menuKind == Kind::End) {
			return false;
		}
	}

	return true;
}

bool ModeTitleMenu::Render() {
	ModeBase::Render();

	//DrawFormatString(600, 600, GetColor(255,255,255), "%d",_menuKind);

	DrawGraph(0, 0, _backHandle, TRUE);
	DrawGraph(_x, _y, _targetHandle, TRUE);

	return true;
}

bool ModeTitleMenu::Terminate() {
	// _cg を解放しないといけないけど、AMLibは個別解放できない・・
	ModeBase::Terminate();

	return true;
}