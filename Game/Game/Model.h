#pragma once
/*

3Dの読み込み
表示のベースクラス

派生クラスにアニメーションとコリジョンクラス

*/
#include "../../AppFrame/ObjectBase.h"
#include "Transform.h"

class Model : public ObjectBase {
public:
	Model();
	virtual ~Model();

	virtual bool Load(const TCHAR* fileName);

	void Process() override;
	void Render() override;

	Transform& GetTransform() {
		return _transform;
	}

protected:
	Transform _transform;

	int _handle;
};