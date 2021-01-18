#pragma once
#include <string>

class SelectComment {
public:

	SelectComment();
	virtual ~SelectComment();

	bool Initialize();
	void Process();
	void Draw();

	void SetString(std::string& script);


private:


	std::string _string;

	bool _isSelectComment;

	int _selectCommentHandle;
	int _x;
	int _y;


};
