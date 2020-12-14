#include "appframe.h"

class ModeGame : public ModeBase{
	typedef ModeBase base;
public:
	//ModeGame();
	//~
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

protected:

	int _cg;
	int _back;
	int _x, _y;

	float _near;
	float _far;


	//////////
	int _attachIndex;
	float _totalTime;
	float _playTime;


}; 
