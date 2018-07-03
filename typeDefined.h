
#define BOARD_HEIGHT 20
#define BOARD_WIDTH 10

typedef enum
{
	EMPTY,
	BLOCK,
	WALL
} ELEMENT;

typedef enum
{
	ESC = 27,
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
	FAILED
} KEY_PRESS;