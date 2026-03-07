#pragma once
#include "raylib.h"
#include <stdbool.h>
#define WIDTH 900
#define HEIGHT 600
#define FPS 60
#define TILESIZE 30
#define ROWS (HEIGHT / TILESIZE)
#define COLUMNS (WIDTH / TILESIZE)
#define START_SNAKE_SIZE 3
#define SNAKE_COLOR RAYWHITE
#define SNAKE_HEAD_START_X (COLUMNS / 2 * TILESIZE);
#define SNAKE_HEAD_START_Y (ROWS / 2 * TILESIZE);


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

typedef enum
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
} Direction;

typedef struct snakeTile
{
	int row;
	int col;
} SnakeTile;

typedef struct snake
{
	SnakeTile *body;
	int length;
	Direction direction;
} Snake;

typedef struct Button
{
	Texture2D button;
	Texture2D button_hovered;
	Rectangle rect;
	Rectangle hitbox;
} Button;

Snake* initSnake(); 
Texture2D getMainMenuTexture(void); // get Texture for main menu from an Image
Button initButton(void); // make a new game button from an Image
bool checkButtonColision(int mouse_x, int mouse_y, Button *newGameButton); // checking if mouse is over the button
void startNewGame(int mouse_x, int mouse_y, Button *newGameButton, State *gameState); // make a new game 



