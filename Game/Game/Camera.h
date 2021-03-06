#pragma once
#include <string>
#include "../../AppFrame/source/appframe.h"

// 計算用マクロ
#define	PI	(3.1415926535897932386f)
#define	DEG2RAD(x)			( ((x) / 180.0f ) * PI )
#define	RAD2DEG(x)			( ((x) * 180.0f ) / PI )

class Camera {
public:
	Camera();
	virtual ~Camera();

	void SetPosition(float x, float y, float z) {
		_vPos = VGet(x, y, z);
	}
	void SetTarget(float x, float y, float z) {
		_vTarget = VGet(x, y, z);
	}

	void SetNearFar(float cNear, float cFar) {
		_clipNear = cNear;
		_clipFar = cFar;
	}

	void Process();
	void Render();  //debug時

	//Dxlibの構造体 float float float
	VECTOR	_vPos;					// 位置
	VECTOR	_vTarget;				// 距離

	//クリップ
	float	_clipNear;
	float _clipFar;

};