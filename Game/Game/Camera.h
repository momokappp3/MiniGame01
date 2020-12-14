#pragma once
#include <string>
#include "../../AppFrame/source/appframe.h"

// �v�Z�p�}�N��
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

	//Dxlib�̍\���� float float float
	VECTOR	_vPos;					// �ʒu
	VECTOR	_vTarget;				// ����

	//�N���b�v
	float	_clipNear;
	float _clipFar;

};