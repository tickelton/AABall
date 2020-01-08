#pragma once
#include <windows.h>
#include <stdio.h>
#include <cstdint>

class AABallConsole {
public:
	AABallConsole();
	void drawFullImage(const LPCWSTR imageData[]);
	void drawAt(const uint16_t x, const uint16_t y, const LPCWSTR imageData);
	void drawBlockAt(const uint16_t x, const uint16_t y, const uint16_t nRows, const LPCWSTR imageData[]);
	void restoreStdout();
private:
	HANDLE hStdout, hScreenBuffers[2];
	COORD bufCoord;
	DWORD nCharsWritten;
};

