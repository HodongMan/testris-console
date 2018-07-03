#include "pch.h"
#include <stdio.h>

void moveCursor(int xPos, int yPos)
{
	COORD position;
	position.X = xPos;
	position.Y = yPos;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void drawOnBoard(int xPos, int yPos, char object)
{
	moveCursor(xPos, yPos);
	printf("%c\n", object);
}

int keyPress(void)
{
	int pressed_key;

	if (_kbhit())
	{
		pressed_key = _getch();
		if ((224 == pressed_key) || (0 == pressed_key))
		{
			pressed_key = _getch();
			return pressed_key;
		}
	}

	return FAILED;
}

void cleanBuffer(void)
{
	while (_kbhit()) _getch();
}