#pragma once
#include "../../AppFrame/source/appframe.h"
#include "Camera.h"
#include <memory>

class Action3DGame : public ModeBase {
public:
	Action3DGame();
	virtual ~Action3DGame();

	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

protected:
	int _pmxModelHandle;

private:

	std::unique_ptr<Camera> _pCamera;

};