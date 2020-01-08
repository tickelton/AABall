#include "AABallBall.h"


const struct BallCoord ballCoordinatesOuter[] = {
	{40, 15},
	{40, 13},
	{41, 11},
	{43, 9},
	{47, 8},
	{53, 7},
	{60, 7},
	{66, 8},
	{70, 9},
	{72, 11},
	{73, 13},
	{73, 15}
};

const struct BallCoord ballCoordinatesCenter[] = {
	{43, 15},
	{43, 13},
	{45, 11},
	{48, 10},
	{53, 9},
	{60, 9},
	{65, 10},
	{68, 11},
	{70, 13},
	{70, 15}
};

const struct BallCoord ballCoordinatesInner[] = {
	{46, 15},
	{47, 13},
	{49, 12},
	{53, 11},
	{60, 11},
	{64, 12},
	{66, 13},
	{67, 15}
};

const ballPositions AllPositions[] = {
	{ballCoordinatesOuter, 12},
	{ballCoordinatesCenter, 10},
	{ballCoordinatesInner, 8}
};

void AABallBall::draw()
{
	for (uint8_t i = 0; i < positions->length; ++i) {
		if (i == pos) {
			c->drawAt(
				positions->coords[i].x,
				positions->coords[i].y,
				L"o"
			);
		}
		else {
			c->drawAt(
				positions->coords[i].x,
				positions->coords[i].y,
				L" "
			);
		}
	}
}

LimbPosition AABallBall::advance()
{
	LimbPosition ret = LimbPosition::NONE;

	if (BallDirection::LEFT == dir) {
		--pos;
		if (0 == pos) {
			dir = BallDirection::RIGHT;
			switch (type) {
			case BallType::OUTER:
				ret = LimbPosition::LEFT;
				break;
			case BallType::CENTER:
				ret = LimbPosition::CENTER;
				break;
			case BallType::INNER:
				ret = LimbPosition::RIGHT;
				break;
			}
		}
	}
	else {
		++pos;
		if (pos == (positions->length)-1) {
			dir = BallDirection::LEFT;
			switch (type) {
			case BallType::OUTER:
				ret = LimbPosition::RIGHT;
				break;
			case BallType::CENTER:
				ret = LimbPosition::CENTER;
				break;
			case BallType::INNER:
				ret = LimbPosition::LEFT;
				break;
			}
		}
	}
	draw();
	return ret;
}

CrashSide AABallBall::getSide()
{
	if (pos > ((positions->length) / 2) - 1) {
		return CrashSide::RIGHT;
	}
	else {
		return CrashSide::LEFT;
	}
}