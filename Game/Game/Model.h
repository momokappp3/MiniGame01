#pragma once
/*

3D�̓ǂݍ���
�\���̃x�[�X�N���X

�h���N���X�ɃA�j���[�V�����ƃR���W�����N���X

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

	VECTOR _vPosition;  //�ꏊ
	VECTOR _vDirection;  //����


	std::list<int> _lHandle;

};