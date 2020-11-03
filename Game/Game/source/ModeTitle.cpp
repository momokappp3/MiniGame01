
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
	// _cg を解放しないといけないけど、AMLibは個別解放できない・・
	base::Terminate();

	return true;
}

bool ModeTitle::Process() {
	base::Process();
	int key = ApplicationMain::GetInstance()->GetKey();  //ApplicatonBaseのメンバ変数_gKey
	int trg = ApplicationMain::GetInstance()->GetTrg();  //押した瞬間しか反応しないキー

	if (trg & PAD_INPUT_4)	{
		ModeServer::GetInstance()->Del(this);  // このモードを削除予約
		ModeServer::GetInstance()->Add(new ModeGame(), 1, "game");  // 次のモードを登録
	}

	return true;
}

bool ModeTitle::Render() {
	base::Render();

	DrawGraph(0, 0, _cg, TRUE);

	return true;
}

