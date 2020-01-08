#include "AABallConsole.h"

AABallConsole::AABallConsole()
{
	// Get a handle to the STDOUT screen buffer to copy from and 
	// create a new screen buffer to copy to. 
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	hScreenBuffers[0] = CreateConsoleScreenBuffer(
		GENERIC_READ |           // read/write access 
		GENERIC_WRITE,
		FILE_SHARE_READ |
		FILE_SHARE_WRITE,        // shared 
		NULL,                    // default security attributes 
		CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE 
		NULL);                   // reserved; must be NULL 

	if (hStdout == INVALID_HANDLE_VALUE ||
		hScreenBuffers[0] == INVALID_HANDLE_VALUE)
	{
		printf("CreateConsoleScreenBuffer failed - (%d)\n", GetLastError());
	}
	else {
		// Make the new screen buffer the active screen buffer. 
		if (!SetConsoleActiveScreenBuffer(hScreenBuffers[0]))
		{
			printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
		}
	}
}

void AABallConsole::drawFullImage(const LPCWSTR imageData[])
{
	bufCoord.X = 0;

	for (int i = 0; i < 30; ++i)
	{
		if (!imageData[i]) {
			continue;
		}
		bufCoord.Y = i;

		BOOL fSuccess = WriteConsoleOutputCharacter(
			hScreenBuffers[0],
			imageData[i],
			static_cast<DWORD>(wcslen(imageData[i])),
			bufCoord,
			&nCharsWritten
		);
		if (!fSuccess)
		{
			printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		}
	}
}

void AABallConsole::restoreStdout()
{
	// Restore the original active screen buffer. 
	if (!SetConsoleActiveScreenBuffer(hStdout))
	{
		printf("SetConsoleActiveScreenBuffer failed - (%d)\n", GetLastError());
	}
}

void AABallConsole::drawAt(const uint16_t x, const uint16_t y, const LPCWSTR imageData)
{
	if (!imageData) {
		return;
	}

	bufCoord.X = x;
	bufCoord.Y = y;

	BOOL fSuccess = WriteConsoleOutputCharacter(
		hScreenBuffers[0],
		imageData,
		static_cast<DWORD>(wcslen(imageData)),
		bufCoord,
		&nCharsWritten
	);
	if (!fSuccess)
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
	}
}

void AABallConsole::drawBlockAt(const uint16_t x, const uint16_t y, const uint16_t nRows, const LPCWSTR imageData[])
{
	bufCoord.X = x;

	for (int i = 0; i < nRows; ++i)
	{
		if (!imageData[i]) {
			continue;
		}
		bufCoord.Y = y + i;

		BOOL fSuccess = WriteConsoleOutputCharacter(
			hScreenBuffers[0],
			imageData[i],
			static_cast<DWORD>(wcslen(imageData[i])),
			bufCoord,
			&nCharsWritten
		);
		if (!fSuccess)
		{
			printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
		}
	}
}