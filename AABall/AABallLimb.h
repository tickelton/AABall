#pragma once
#include "AABall.h"
#include "AABallConsole.h"

extern LPCWSTR limbsImages[][30];

class AABallLimb {
public:
	AABallLimb(AABallConsole& con) : c(&con) {}
	void draw();
	LimbPosition getPosition();
	AABallLimb& operator++();
	AABallLimb operator++(int);
	AABallLimb& operator--();
	AABallLimb operator--(int);
private:
	AABallConsole* c;
	LimbPosition pos = LimbPosition::CENTER;
};


