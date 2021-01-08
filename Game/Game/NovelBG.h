#pragma once

/*

背景を描画するかのフラグを
管理するクラス

選択肢の画像の位置どうしよう

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