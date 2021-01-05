#pragma once

class MouseInput {
public:
	MouseInput();
	virtual ~MouseInput();

	void Process();
	void Draw();

private:
	int _posX;
	int _posY;
};