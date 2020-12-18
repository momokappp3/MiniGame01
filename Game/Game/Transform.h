#pragma once
#include "DxLib.h"

class Transform {
public:
	static float ToRadian(float angle);
	static float ToAngle(float radian);

	Transform();
	virtual ~Transform();

	void SetBaseDirection(float x, float y, float z) {
		_vBaseDirection = VNorm(VGet(x, y, z));
	}

	void Forward(float speed);
	void SetRotateY(float angle);
	void AddRotateY(float angle);
	void Update();

	void SetScale(float x, float y, float z) {
		_vScale = VGet(x, y, z);
	}

	void AddScale(float x, float y, float z) {
		_vScale = VGet(_vScale.x + x, _vScale.y + y, _vScale.z + z);
	}

	void SetDirection(float x, float y, float z) {
		_vDirection = VNorm(VGet(x, y, z));
	}

	void AddDirection(float x, float y, float z) {
		_vDirection = VNorm(VGet(_vDirection.x + x, _vDirection.y + y, _vDirection.z + z));
	}

	void SetPosition(float x, float y, float z) {
		_vPosition = VGet(x, y, z);
	}

	void AddPosition(float x, float y, float z) {
		_vPosition = VGet(_vPosition.x + x, _vPosition.y + y, _vPosition.z + z);
	}

	VECTOR GetScale() const {
		return _vScale;
	}

	VECTOR GetDirection() const {
		return _vDirection;
	}

	VECTOR GetPosition() const {
		return _vPosition;
	}

	MATRIX GetTransform() const {
		return _mTransform;
	}

private:
	VECTOR _vScale;  // �g��k��

	VECTOR _vBaseDirection;  //�ŏ��̌���(���f���̍��ɂ���ĈႤ)
	VECTOR _vDirection;  //����

	VECTOR _vPosition;  //�ꏊ

	MATRIX _mTransform;  //�ϊ��s��
};