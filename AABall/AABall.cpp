#include <windows.h> 
#include <stdio.h>
#include <cstdint>
#include "AABall.h"
#include "AABall_images.h"
#include "AABallConsole.h"
#include "AABallScore.h"
#include "AABallInput.h"
#include "AABallLimb.h"
#include "AABallBall.h"
#include "AABallQueue.h"

// main loop cycle time in ms
const uint16_t sleepInterval = 10;
// ball positions change every sleepInverval*ballInterval
const uint16_t ballInterval = 50;
const double speedupFactor = 0.9;
// number of times the speed increases until it resets
const uint8_t speedupCycles = 10;
// number of catches between speed increases
const uint8_t speedupBallCount = 10;


int main(void)
{
	GameType gameType = GameType::NONE;
	uint8_t speedupCycleCount = 0;
	uint8_t ballCycleCount = 0;
	uint8_t ballCount = 0;
	LimbPosition catchPosition = LimbPosition::NONE;
	uint16_t actualballInterval = ballInterval;

	AABallConsole c;
	AABallScore score(c);
	AABallLimb limbs(c);
	AABallQueue ballQueue;
	AABallInput input;

	c.drawFullImage(staticImage);
	limbs.draw();
	score.draw();

	bool gotQuit = false;
	while (!gotQuit) {
		if (input.ready()) {
			switch (input.getKey())
			{
			case AAKeyEvent::KEY_QUIT:
				gotQuit = true;
				break;
			case AAKeyEvent::KEY_LEFT:
				if (GameType::NONE != gameType) {
					--limbs;
				}
				break;
			case AAKeyEvent::KEY_RIGHT:
				if (GameType::NONE != gameType) {
					++limbs;
				}
				break;
			case AAKeyEvent::KEY_GAME_A:
				gameType = GameType::GAME_A;
				c.drawFullImage(staticImage);
				limbs.draw();
				score.draw();
				ballQueue.start(c, gameType);
				break;
			case AAKeyEvent::KEY_GAME_B:
				gameType = GameType::GAME_B;
				c.drawFullImage(staticImage);
				limbs.draw();
				score.draw();
				ballQueue.start(c, gameType);
				break;
			default:
				break;
			}
		}

		if (GameType::NONE != gameType) {
			if ((actualballInterval - 1) == ballCycleCount) {
				if (LimbPosition::NONE != catchPosition) {
					if (limbs.getPosition() == catchPosition)
					{
						++score;
						ballCount = (ballCount + 1) % speedupBallCount;
							if (0 == ballCount) {
								speedupCycleCount = (speedupCycleCount + 1) % speedupCycles;
								if (0 == speedupCycleCount) {
									actualballInterval = ballInterval;
								}
								else {
 									actualballInterval = static_cast<int>(actualballInterval * speedupFactor);
								}
							}
					}
					else {
						gameType = GameType::NONE;
						c.drawBlockAt(27, 17, 6, crushImages[0]);
						c.drawBlockAt(76, 17, 6, crushImages[0]);
						if (CrashSide::LEFT == ballQueue.getCrashSide())
						{
							c.drawBlockAt(35, 21, 6, crushImages[1]);
						}
						else {
							c.drawBlockAt(65, 21, 6, crushImages[2]);
						}
					}
				}
				catchPosition = ballQueue.advance();
			}
			ballCycleCount = (ballCycleCount + 1) % actualballInterval;
		}

		Sleep(sleepInterval);
	}

	c.restoreStdout();

	return 0;
}