#ifndef LOGIC_H
#define LOGIC_H
#define WIDTH 900
#define HEIGHT 600
#define FPS 60
#define TILESIZE 30
#define ROWS (HEIGHT / TILESIZE)
#define COLUMNS (WIDTH / TILESIZE)
#define START_SNAKE_SIZE 3


typedef enum 
{
	NEW_GAME,
	PLAYING,
	GAME_OVER
} state;

typedef enum
{
	EMPTY,
	APPLE,
	SNAKE,
} tileTypes;

typedef struct snakeTile
{
	int row;
	int col;
} snakeTile;


#endif
