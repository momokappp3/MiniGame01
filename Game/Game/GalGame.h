#pragma once
#include "../../AppFrame/source/appframe.h"
#include <memory>
#include "Camera.h"
#include "Model.h"
#include "../../AppFrame/MouseInput.h"

class GalGame : public ModeBase {
public:
	GalGame();
	virtual ~GalGame();

	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

private:

	std::unique_ptr<Camera> _pCamera;
	std::unique_ptr<Model> _pCharaModel;
	std::unique_ptr<Model> _pRoomModel;
	std::unique_ptr<MouseInput> _pMouseInput;

};