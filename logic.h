#pragma once
#include "raylib.h"
#include <stdbool.h>
#define WIDTH 900
#define HEIGHT 600
#define FPS 60
#define MAX_FRAME_TIME 0.12f
#define TILESIZE 30
#define ROWS (HEIGHT / TILESIZE)
#define COLUMNS (WIDTH / TILESIZE)
#define START_SNAKE_SIZE 3
#define SNAKE_COLOR GREEN
#define SNAKE_HEAD_START_X (COLUMNS / 2 * TILESIZE)
#define SNAKE_HEAD_START_Y (ROWS / 2 * TILESIZE)
#define APPLE_COLOR RED


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
	int x_pos;
	int y_pos;
} SnakeTile;

typedef struct snake
{
	SnakeTile body[ROWS * COLUMNS];
	int length;
	Direction direction;
	Direction lastDir;
} Snake;

typedef struct Button
{
	Texture2D button;
	Texture2D button_hovered;
	Rectangle rect;
	Rectangle hitbox;
} Button;

Snake* initSnake(TileTypes field[ROWS][COLUMNS]); // init snake with starting size and position
void moveSnake(Snake *snake, TileTypes field[ROWS][COLUMNS], State *gameState); // calculationg where snake body should be 
void findDirection(Snake *snake); // depend on buttons pressed finding direction
bool checkSnakeColision(Snake *snake); // checking if snake is out of field or eating itself
void growSnake(Snake *snake, int old_tail_x, int old_tail_y); // growing snake if it eats an apple
void initField(TileTypes field[ROWS][COLUMNS]); // init field with EMPTY
void clearField(TileTypes field[ROWS][COLUMNS]); // fill the field with EMPTY if not APPLE;
void putApple(TileTypes field[ROWS][COLUMNS]); // put an APPLE in EMPTY field
void deleteOldGame(Snake **snake, TileTypes field[ROWS][COLUMNS]); // delete old game and make new one
Texture2D getMainMenuTexture(void); // get Texture for main menu from an Image
Texture2D getGameOverTexture(void); // get Texture for game over screen from an Image
Button initButton(void); // make a new game button from an Image
bool checkButtonColision(int mouse_x, int mouse_y, Button *newGameButton); // checking if mouse is over the button
void startNewGame(int mouse_x, int mouse_y, Button *newGameButton, State *gameState, Snake **snake, TileTypes field[ROWS][COLUMNS]); // make a new game 



