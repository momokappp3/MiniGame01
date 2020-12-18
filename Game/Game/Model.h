#pragma once
/*

3Dの読み込み
表示のベースクラス

派生クラスにアニメーションとコリジョンクラス

*/
#include"../../AppFrame/source/appframe.h"
#include <List>

class Model {
public:
	Model();
	virtual ~Model();

	enum class KIND {
		Player,
		Tue,
		Stage
	};

	virtual bool Initialize();
	virtual void Process();
	virtual void Render();

	int GetHandle(KIND kind) {
		//return _lHandle;
	}

private:

	VECTOR _vPosition;  //場所
	VECTOR _vDirection;  //向き


	std::list<int> _lHandle;

};