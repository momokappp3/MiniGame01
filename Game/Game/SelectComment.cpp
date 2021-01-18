#include "SelectComment.h"
#include "DxLib.h"
#include "ResourceServer.h"

SelectComment::SelectComment() {

	_isSelectComment = false;

	_selectCommentHandle = -1;
	_x = 0;
	_y = 0;
}

SelectComment::~SelectComment() {
}

bool SelectComment::Initialize() {

	_selectCommentHandle = ResourceServer::LoadGraph(_T("res/myComment.png"));

	return true;
}

void SelectComment::Process() {

	const auto size = _string.size();



}



void SelectComment::SetString(std::string& script) {
	_string = script;
}

void SelectComment::Draw() {

	if (_isSelectComment) {
		DrawGraph(_x, _y, _selectCommentHandle, TRUE);
		DrawFormatString(_x, _y, GetColor(255, 0, 0), "%s", _string);
	}
}