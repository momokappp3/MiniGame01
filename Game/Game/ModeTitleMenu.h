#pragma once
#include "source/ApplicationMain.h"
#include "../../AppFrame/Input.h"
#include <memory>

class ModeTitleMenu : public ModeBase{
public:
	ModeTitleMenu();
	virtual ~ModeTitleMenu();

	enum class Kind {
		NewGame = 0,
		LoadGame,
		EndGame,
		Option,
		Help,
		End,
		Max
	};

	virtual bool Initialize();
	virtual bool Terminate();
	virtual bool Process();
	bool Render()override;

private:

	std::unique_ptr<Input> _pInput;

	Kind _menuKind;

	int _enterInput;


	int _backHandle;
	int _targetHandle;

	int _x, _y;
};