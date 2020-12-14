#pragma once
/*

3Dの読み込み
表示のベースクラス

派生クラスにアニメーションとコリジョンクラス

*/
#include"../../AppFrame/source/appframe.h"

class Model {
public:
	Model();
	virtual ~Model();

	enum class Kind {
		Player,
		Tue,
		Stage
	};

	virtual void Process();
	virtual void Render();

private:

	VECTOR _vPosition;  //場所
	VECTOR _vDirection;  //向き

};