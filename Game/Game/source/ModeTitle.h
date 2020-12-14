#include "appframe.h"

class ModeTitle : public ModeBase{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

protected:
	int _cg;
}; 
