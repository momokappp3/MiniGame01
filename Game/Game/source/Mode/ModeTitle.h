#pragma once
#include "appframe.h"
#include "../../../../AppFrame/Input.h"
#include <memory>

class ModeTitle : public ModeBase{
public:
	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	virtual bool Render();

private:

	std::unique_ptr<Input> _pInput;

	int _backHandle;
	int _key;
}; 
