#include "AABallScore.h"

AABallScore& AABallScore::operator++()
{
	scoreValue = (scoreValue + 1 ) % 10000;
	draw();
	return *this;
}

AABallScore AABallScore::operator++(int)
{
	AABallScore tmp(*this);
	operator++();
	return tmp;
}

void AABallScore::draw()
{
	wchar_t buf[8];

	swprintf_s(
		buf,
		8,
		L"%d %d %d %d",
		(scoreValue / 1000) % 10,
		(scoreValue / 100) % 10,
		(scoreValue / 10) % 10,
		scoreValue % 10
	);
	c->drawAt(83, 6, buf);
}
