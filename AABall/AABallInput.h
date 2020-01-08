#pragma once
#include <windows.h> 
#include <cstdint>
#include "AABall.h"

class AABallInput {
public:
	AABallInput();
	bool ready();
	AAKeyEvent getKey();
private:
	HANDLE hStdin;
	INPUT_RECORD irInBuf[1];
	DWORD cNumRead;
	
};

