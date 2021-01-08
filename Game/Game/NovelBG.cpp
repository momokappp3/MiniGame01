#include "NovelBG.h"
#include "ResourceServer.h"
#include "Dxlib.h"

NovelBG::NovelBG() {

	_isNovel = false;
	_isSelectComment = true;
	_isComment = true;

	_novelHandle = -1;
	_selectCommentHandle = -1;
	_commentHandle = -1;
}
NovelBG::~NovelBG() {
}

bool NovelBG::Initialize() {

	_novelHandle = ResourceServer::LoadGraph(_T("res/novel.png"));
	_selectCommentHandle = ResourceServer::LoadGraph(_T("res/myComment.png"));
	_commentHandle = ResourceServer::LoadGraph(_T("res/comment.png"));

	if (_novelHandle == -1 || _selectCommentHandle == -1 || _commentHandle == -1) {
		return false;
	}

	return true;
}

void NovelBG::Process() {

}

void NovelBG::Draw() {

	if (_isSelectComment) {
		DrawGraph(0, 0, _selectCommentHandle, TRUE);
	}

	if (_isComment) {
		DrawGraph(200, 700, _commentHandle, TRUE);
	}

	if (_isNovel) {
		DrawGraph(200, 200, _novelHandle, TRUE);
	}
}