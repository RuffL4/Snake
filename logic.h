#pragma once
#include "raylib.h"
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
} State;

typedef enum
{
	EMPTY,
	APPLE,
	SNAKE,
} TileTypes;

typedef struct snakeTile
{
	int row;
	int col;
} SnakeTile;

typedef struct Button
{
	Texture2D button;
	Texture2D button_hovered;
	Rectangle rect;
} Button;

Texture2D getMainMenuTexture(void);
Button initButton(void);



