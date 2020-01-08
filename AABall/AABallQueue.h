#pragma once
#include "AABall.h"
#include "AABallLimb.h"
#include "AABallBall.h"

class AABallQueue {
public:
	LimbPosition advance();
	void start(AABallConsole &c, GameType type);
	CrashSide getCrashSide();
private:
	AABallBall* queue[3] = { nullptr, nullptr, nullptr };
	AABallBall* ball;
	int8_t idx = 0;
};


