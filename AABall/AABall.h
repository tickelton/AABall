#pragma once

enum class AAKeyEvent {
	KEY_LEFT,
	KEY_RIGHT,
	KEY_QUIT,
	KEY_GAME_A,
	KEY_GAME_B,
	KEY_NONE
};

enum class LimbPosition {
	LEFT = 0,
	CENTER = 1,
	RIGHT = 2,
	NONE
};

enum class BallType {
	OUTER = 0,
	CENTER = 1,
	INNER = 2
};

enum class BallDirection {
	LEFT,
	RIGHT
};

enum class CrashSide {
	LEFT,
	RIGHT
};

enum class GameType {
	GAME_A,
	GAME_B,
	NONE
};

