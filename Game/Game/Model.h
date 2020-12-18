#pragma once
/*

3D�̓ǂݍ���
�\���̃x�[�X�N���X

�h���N���X�ɃA�j���[�V�����ƃR���W�����N���X

*/
#include "../../AppFrame/ObjectBase.h"
#include "Transform.h"

class Model : public ObjectBase {
public:
	Model();
	virtual ~Model();

	bool LoadModel(const TCHAR* fileName);

	void Process() override;
	void Render() override;

	Transform GetTransform() const {
		return _transform;
	}

private:
	Transform _transform;

	int _handle;
};