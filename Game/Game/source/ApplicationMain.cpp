/*

���[�h�̓o�^

*/
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeTitle.h"

// ����
ApplicationMain	g_oApplicationMain;

bool ApplicationMain::Initialize(HINSTANCE hInstance) {
	if (!ApplicationBase::Initialize(hInstance)) { return false; }

	// ���[�h�̓o�^
	ModeServer::GetInstance()->Add(new ModeTitle(), 1, "title");

	return true;
}

bool ApplicationMain::Terminate() {
	ApplicationBase::Terminate();
	return true;
}


bool ApplicationMain::Input() {
	ApplicationBase::Input();
	return true;
}

bool ApplicationMain::Process() {
	ApplicationBase::Process();
	return true;
}

bool ApplicationMain::Render() {
	ApplicationBase::Render();
	return true;
}

