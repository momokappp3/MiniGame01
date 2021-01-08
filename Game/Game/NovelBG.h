#pragma once

/*

�w�i��`�悷�邩�̃t���O��
�Ǘ�����N���X

�I�����̉摜�̈ʒu�ǂ����悤

*/

class NovelBG {
public:
	NovelBG();
	virtual ~NovelBG();

	bool Initialize();
	//void Process();
	void Draw();

	void SetNovelFlag(bool flag) {
		_isNovel = flag;
	}
	void SetSelectCommentFlag(bool flag) {
		_isSelectComment = flag;
	}
	void SetCommentFlag(bool flag) {
		_isComment = flag;
	}

private:

	bool _isNovel;
	bool _isSelectComment;
	bool _isComment;

	int _novelHandle;
	int _selectCommentHandle;
	int _commentHandle;
};