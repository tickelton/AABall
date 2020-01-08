#include "AABallQueue.h"


void AABallQueue::start(AABallConsole &c, GameType type)
{
	if (queue[0]) {
		delete queue[0];
		queue[0] = nullptr;
	}
	if (queue[1]) {
		delete queue[1];
		queue[1] = nullptr;
	}
	if (queue[2]) {
		delete queue[2];
		queue[2] = nullptr;
	}

	if (type == GameType::GAME_A)
	{
		queue[0] = new AABallBall(c, BallType::OUTER);
		queue[0]->draw();
		queue[1] = new AABallBall(c, BallType::CENTER);
		queue[1]->draw();
	}
	else if (type == GameType::GAME_B)
	{
		queue[0] = new AABallBall(c, BallType::OUTER);
		queue[0]->draw();
		queue[1] = new AABallBall(c, BallType::CENTER);
		queue[1]->draw();
		queue[2] = new AABallBall(c, BallType::INNER);
		queue[2]->draw();
	}

	idx = 0;
	ball = queue[idx];
}

LimbPosition AABallQueue::advance()
{
	LimbPosition ret = ball->advance();

	idx = (idx + 1) % 3;
	if (queue[idx])
	{
		ball = queue[idx];
	}
	else
	{
		idx = 0;
		ball = queue[idx];
	}

	return ret;
}

CrashSide AABallQueue::getCrashSide()
{
	return queue[(idx - 1) % 3]->getSide();
}