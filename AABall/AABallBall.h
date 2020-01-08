#pragma once

#include <cstdint>
#include "AABall.h"
#include "AABallConsole.h"


struct BallCoord {
	uint16_t x;
	uint16_t y;
};

struct ballPositions {
	const struct BallCoord* coords;
	uint8_t length;
};

extern const ballPositions AllPositions[];

class AABallBall {
public:
	AABallBall(AABallConsole& con, BallType t) : c(&con), type(t)
	{
		positions = &AllPositions[static_cast<int>(t)];
		pos = rand() % positions->length;
		if (pos > ((positions->length)/2)-1) {
			dir = BallDirection::LEFT;
		}
		else {
			dir = BallDirection::RIGHT;
		}
	}
	void draw();
	LimbPosition advance();
	CrashSide getSide();
private:
	AABallConsole* c;
	BallType type;
	BallDirection dir;
	const struct ballPositions* positions;
	uint8_t pos;
	uint8_t pos_max;
};



