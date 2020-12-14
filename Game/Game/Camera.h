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

	bool SetPosition(float x, float y, float z);
	bool SetTarget(float x, float y, float z);
	bool SetNearFar();
	void Process();
	void Render();

	//Dxlibの構造体 float float float
	VECTOR	_vPos;					// 位置
	VECTOR	_vTarget;				// 距離

	//クリップ
	float	_clipNear;
	float _clipFar;

};