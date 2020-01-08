#pragma once
#include <stdio.h>
#include <cstdint>
#include "AABallConsole.h"

class AABallScore {
public:
	AABallScore(AABallConsole& con) : c(&con) {}
	void draw();
	AABallScore& operator++();
	AABallScore operator++(int);
private:
	AABallConsole* c;
	uint16_t scoreValue = 0;
};
