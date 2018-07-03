#ifndef _BOARD_H_
#define _BOARD_H_


typedef struct
{
	unsigned int currentStage;
	unsigned int speed;
	unsigned int bonus;
	unsigned int removeLineCount;
}Stage;

typedef struct
{
	unsigned int score;
	unsigned int nextScore;
}Score;

typedef struct
{
	unsigned int blockType;
	unsigned int blockRotation;
	unsigned int nextBlock;
	unsigned int blockXPos;
	unsigned int blockYPos;
	unsigned int isCollision;
}Block;

typedef struct
{
	char board[BOARD_WIDTH + 2][BOARD_HEIGHT + 2];
	Stage* stage;
	Score* score;
	Block* block;

}Board;

Board* initBoard();
Stage* initStage();
Score* initScore();
Block* initBlock();

#endif