#include "pch.h"
#include <stdio.h>

void drawBoard(void)
{
	int i, j;
	for (i = 0; i < BOARD_WIDTH + 2; ++i)
	{
		for (j = 0; j < BOARD_HEIGHT + 2; ++j)
		{
			//drawOnBoard(i, j, "");
		}
	}

	moveCursor(20, 3);
	printf("Tetris Ver 1.0");
	moveCursor(50, 5);
	printf("좌우 : 이동, 위 : 회전, 아래 : 내림");
	moveCursor(50, 6);
	printf("공백 : 전부 내림");
}

void openIndexScreen(void) {
	int xPos = 5;  
	int yPos = 4;  
	int frame; 

	moveCursor(xPos, yPos + 0);		printf("■□□□■■■□□■■□□■■"); Sleep(100);
	moveCursor(xPos, yPos + 1);		printf("■■■□  ■□□    ■■□□■"); Sleep(100);
	moveCursor(xPos, yPos + 2);		printf("□□□■              □■  ■"); Sleep(100);
	moveCursor(xPos, yPos + 3);		printf("■■□■■  □  ■  □□■□□"); Sleep(100);
	moveCursor(xPos, yPos + 4);		printf("■■  ■□□□■■■□■■□□"); Sleep(100);
	moveCursor(xPos + 5, yPos + 2);	printf("T E T R I S"); Sleep(100);
	moveCursor(xPos, yPos + 7);		printf("Please Enter Any Key to Start..");
	moveCursor(xPos, yPos + 9);		printf("  △   : Shift");
	moveCursor(xPos, yPos + 10);		printf("◁  ▷ : Left / Right");
	moveCursor(xPos, yPos + 11);		printf("  ▽   : Soft Drop");
	moveCursor(xPos, yPos + 12);		printf(" SPACE : Hard Drop");
	moveCursor(xPos, yPos + 13);		printf("   P   : Pause");
	moveCursor(xPos, yPos + 14);		printf("  ESC  : Quit");
	moveCursor(xPos, yPos + 16);		printf("BONUS FOR HARD DROPS / COMBOS");

	for (frame = 0;; ++frame)
	{
		if (_kbhit())
		{
			break;
		}
		if (frame % 200 == 0) 
		{ 
			moveCursor(xPos + 4, yPos + 1); 
			printf("★"); 
		}        
		else if ((frame % 200 - 100) == 0) 
		{ 
			moveCursor(xPos + 4, yPos + 1);
			printf("  "); 
		}  
		else if ((frame % 350) == 0) 
		{ 
			moveCursor(xPos + 13, yPos + 2);
			printf("☆"); 
		}  
		else if ((frame % 350 - 100) == 0) 
		{ 
			moveCursor(xPos + 13, yPos + 2);
			printf("  "); 
		}
		Sleep(10);   
	}

	cleanBuffer();
}

Board* initBoard()
{
	srand(time(NULL));
	Board* board = (Board*)malloc(sizeof(Board));
	Score* score = initScore();
	Stage* stage = initStage();
	Block* block = initBlock();

	stage->currentStage = 1;
	stage->speed = 100;
	stage->removeLineCount = 0;
	score->score = 0;
	score->nextScore = 1000;
	block->isCollision = FALSE;
	block->nextBlock = rand() % 7 + 1;

	board->score = score;
	board->stage = stage;
	board->block = block;

	return board;
}

Score* initScore()
{
	Score* score = (Score*)malloc(sizeof(Score));
	
	if (NULL == score)
	{
		return score;
	}

	score->nextScore = 0;
	score->score = 0;

	return score;
}

Stage* initStage()
{
	Stage* stage = (Stage*)malloc(sizeof(Stage));
	
	if (NULL == stage)
	{
		return NULL;
	}

	stage->currentStage = 0;
	stage->speed = 0;
	stage->bonus = 0;
}

Block* initBlock()
{
	Block* block = (Block*)malloc(sizeof(Block));
	
	if (NULL == block)
	{
		return NULL;
	}

	block->blockRotation = 0;
	block->blockType = 0;
	block->blockXPos = 0;

	return block;
}