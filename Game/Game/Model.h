#pragma once
/*

3D�̓ǂݍ���
�\���̃x�[�X�N���X

�h���N���X�ɃA�j���[�V�����ƃR���W�����N���X

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

	VECTOR _vPosition;  //�ꏊ
	VECTOR _vDirection;  //����

};