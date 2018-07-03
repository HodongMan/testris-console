#ifndef _LIB_UTIL_H_
#define _LIB_UTIL_H_

#include <conio.h>
#include <windows.h>

void moveCursor(int xPos, int yPos);
void drawOnBoard(int xPos, int yPos, char object);
int keyPress(void);
void cleanBuffer(void);

#endif