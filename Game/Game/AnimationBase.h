#pragma once

#include <unordered_map>
#include "Model.h"

class AnimationBase : public Model {
public:
	AnimationBase();
	virtual ~AnimationBase();

	bool Load(const TCHAR* fileName) override;
	void Process() override;

	bool Play(int index, int blendFrame = 0);
	void Stop();

	bool Attach(int index);
	bool Detach(int index);

	float GetTime(int index);

protected:
	void ProcessBlend();
	bool ImmediatePlay(int index);

	int _animationNum;
	int _playIndex;

	int _blendIndex;
	int _blendFrame;
	int _blendCount;

	std::unordered_map<int, float> _mapAnimationTime;
};
