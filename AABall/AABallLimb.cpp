#include "AABallLimb.h"

AABallLimb& AABallLimb::operator++()
{
	switch (pos) {
	case LimbPosition::LEFT:
		pos = LimbPosition::CENTER;
		break;
	case LimbPosition::CENTER:
		pos = LimbPosition::RIGHT;
		break;
	default:
		break;
	}

	draw();
	return *this;
}

AABallLimb AABallLimb::operator++(int)
{
	AABallLimb tmp(*this);
	operator++();
	return tmp;
}

AABallLimb& AABallLimb::operator--()
{
	switch (pos) {
	case LimbPosition::RIGHT:
		pos = LimbPosition::CENTER;
		break;
	case LimbPosition::CENTER:
		pos = LimbPosition::LEFT;
		break;
	default:
		break;
	}

	draw();
	return *this;
}

AABallLimb AABallLimb::operator--(int)
{
	AABallLimb tmp(*this);
	operator++();
	return tmp;
}

void AABallLimb::draw()
{
	c->drawFullImage(limbsImages[static_cast<int>(pos)]);
}

LimbPosition AABallLimb::getPosition() {
	return pos;
}

