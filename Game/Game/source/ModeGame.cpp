#include "AppFrame.h"
#include "ApplicationMain.h"
#include "ModeGame.h"

bool ModeGame::Initialize() {

	if (!base::Initialize()) {
		return false; 
	}

	_cg = MV1LoadModel("model/rori.pmx");
	_x = 0;
	_y = 0;

	//奥行0.1～1000までをカメラの描画範囲とする(カメラの初期位置)
	SetCameraNearFar(0.1f, 800.0f);

	//(0,10,-20)の視点から(0,10,0)のターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));

	_attachIndex = MV1AttachAnim(_cg, 1, -1, FALSE);

	_totalTime = MV1GetAttachAnimTotalTime(_cg, _attachIndex);

	_playTime = 0.0f;

	return true;
}

bool ModeGame::Terminate() {
	base::Terminate();
	return true;
}

bool ModeGame::Process() {
	base::Process();

	int key = ApplicationMain::GetInstance()->GetKey();







	if (key & PAD_INPUT_LEFT)	{ 
		// 再生時間を進める
		_playTime += 0.2f;

		// 再生時間がアニメーションの総再生時間に達したら再生時間を０に戻す
		if (_playTime >= _totalTime) {
			_playTime = 0.0f;
		}

		// 再生時間をセットする
		MV1SetAttachAnimTime(_cg, _attachIndex, _playTime);


	}

	if (key & PAD_INPUT_RIGHT)	{ _x += 8; }
	if (key & PAD_INPUT_UP)		{ _y -= 8; }
	if (key & PAD_INPUT_DOWN)	{ _y += 8; }


	//test

	return true;
}

bool ModeGame::Render() {
	base::Render();

	MV1DrawModel(_cg);

	return true;
}

