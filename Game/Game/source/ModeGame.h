#include "appframe.h"

class ModeGame : public ModeBase{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

protected:

	int _cg;
	int _cg2;
	int _back;
	int _x, _y;

	float _near;
	float _far;

	int _attachIndex;
	int _attachIndex2;
	float _totalTime;
	float _totalTime2;
	float _playTime;
	float _playTime2;

}; 
