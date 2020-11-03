
#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeTitle.h"
#include "ModeGame.h"

bool ModeTitle::Initialize() {
	if (!base::Initialize()) {
		return false; 
	}

	_cg = LoadGraph("res/title.png");

	return true;
}

bool ModeTitle::Terminate() {
	// _cg ��������Ȃ��Ƃ����Ȃ����ǁAAMLib�͌ʉ���ł��Ȃ��E�E
	base::Terminate();

	return true;
}

bool ModeTitle::Process() {
	base::Process();
	int key = ApplicationMain::GetInstance()->GetKey();  //ApplicatonBase�̃����o�ϐ�_gKey
	int trg = ApplicationMain::GetInstance()->GetTrg();  //�������u�Ԃ����������Ȃ��L�[

	if (trg & PAD_INPUT_4)	{
		ModeServer::GetInstance()->Del(this);  // ���̃��[�h���폜�\��
		ModeServer::GetInstance()->Add(new ModeGame(), 1, "game");  // ���̃��[�h��o�^
	}

	return true;
}

bool ModeTitle::Render() {
	base::Render();

	DrawGraph(0, 0, _cg, TRUE);

	return true;
}

