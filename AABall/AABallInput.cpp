#include "AABallInput.h"

AABallInput::AABallInput()
{
	hStdin = GetStdHandle(STD_INPUT_HANDLE);
}

bool AABallInput::ready()
{
	if (!PeekConsoleInput(
		hStdin,      // input buffer handle 
		irInBuf,     // buffer to read into 
		1,         // size of read buffer 
		&cNumRead)) // number of records read 
		return false;
	if (cNumRead)
		return true;
	return false;
}

AAKeyEvent AABallInput::getKey()
{
	if (!ReadConsoleInput(
		hStdin,      // input buffer handle 
		irInBuf,     // buffer to read into 
		1,         // size of read buffer 
		&cNumRead)) // number of records read 
		return AAKeyEvent::KEY_NONE;

	for (uint32_t i = 0; i < cNumRead; i++)
	{
		switch (irInBuf[i].EventType)
		{
		case KEY_EVENT: // keyboard input 
			if (irInBuf[i].Event.KeyEvent.bKeyDown &&
				irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 'q')
			{
				return AAKeyEvent::KEY_QUIT;
			}
			else if (irInBuf[i].Event.KeyEvent.bKeyDown &&
				irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 'a')
			{
				return AAKeyEvent::KEY_LEFT;
			}
			else if (irInBuf[i].Event.KeyEvent.bKeyDown &&
				irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 'd')
			{
				return AAKeyEvent::KEY_RIGHT;
			}
			else if (irInBuf[i].Event.KeyEvent.bKeyDown &&
				irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 'n')
			{
				return AAKeyEvent::KEY_GAME_A;
			}
			else if (irInBuf[i].Event.KeyEvent.bKeyDown &&
				irInBuf[i].Event.KeyEvent.uChar.AsciiChar == 'm')
			{
				return AAKeyEvent::KEY_GAME_B;
			}
			break;
		default:
			break;
		}
	}

	return AAKeyEvent::KEY_NONE;
}