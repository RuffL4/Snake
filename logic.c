#include "raylib.h"
#include "logic.h"
#include <stdlib.h>
#include <stdbool.h>


Snake* initSnake(TileTypes field[ROWS][COLUMNS])
{
	Snake *snake = malloc(sizeof(Snake));
	if(snake == NULL) return NULL;

	snake->direction = LEFT;
	snake->lastDir = LEFT;
	snake->length = START_SNAKE_SIZE;
	
	int snake_x = SNAKE_HEAD_START_X;
	int snake_y = SNAKE_HEAD_START_Y;

	int row = snake_y / TILESIZE;
	int col;

	for (int tile = 0; tile < START_SNAKE_SIZE; tile++)
	{
		snake->body[tile].x_pos = snake_x;
	       	snake->body[tile].y_pos = snake_y;
		col = snake_x / TILESIZE;
		field[row][col] = SNAKE;
		snake_x += TILESIZE; 	
	}
	
	return snake;
}

void moveSnake(Snake *snake, TileTypes field[ROWS][COLUMNS], State *gameState)
{
	clearField(field);
	int tail_index = snake->length - 1;
	int old_tail_x = snake->body[tail_index].x_pos; 
	int old_tail_y = snake->body[tail_index].y_pos;

	for (int tile = tail_index; tile > 0; tile--)
	{
		int next_tile = tile - 1;
		snake->body[tile].x_pos = snake->body[next_tile].x_pos;
		snake->body[tile].y_pos = snake->body[next_tile].y_pos;
	}
	
	switch(snake->direction)
	{
		case UP:
			snake->body[0].y_pos -= TILESIZE;
			break;
		case DOWN:
			snake->body[0].y_pos += TILESIZE;
			break;
		case RIGHT:
			snake->body[0].x_pos += TILESIZE;
			break;
		case LEFT:
			snake->body[0].x_pos -= TILESIZE;
			break;
	}

	if(checkSnakeColision(snake))
	{
		*gameState = GAME_OVER;
		return;
	}

	int head_row = snake->body[0].y_pos / TILESIZE;
	int head_col = snake->body[0].x_pos / TILESIZE;
	bool ate_apple = false;

	if(field[head_row][head_col] == APPLE)
	{
		ate_apple = true;
		if(snake->length == ROWS * COLUMNS)
		{
			*gameState = GAME_OVER; 
			return;
		}
		growSnake(snake, old_tail_x, old_tail_y);
	}

	int snake_length = snake->length;
	for(int tile = 0; tile < snake_length; tile++)
	{
		int row = snake->body[tile].y_pos / TILESIZE;
		int col = snake->body[tile].x_pos / TILESIZE;
		field[row][col] = SNAKE;
	}

	if(ate_apple) putApple(field);

	snake->lastDir = snake->direction;
}

void findDirection(Snake *snake)
{
	Direction last = snake->lastDir;
	if(IsKeyPressed(KEY_UP) && last != DOWN) snake->direction = UP;
	else if(IsKeyPressed(KEY_DOWN) && last != UP) snake->direction = DOWN;
	else if(IsKeyPressed(KEY_RIGHT) && last != LEFT) snake->direction = RIGHT;
	else if(IsKeyPressed(KEY_LEFT) && last != RIGHT) snake->direction = LEFT;
}

bool checkSnakeColision(Snake *snake)
{
	int head_x = snake->body[0].x_pos;
	int head_y = snake->body[0].y_pos;
	if (head_x < 0 || head_x >= WIDTH || head_y < 0 || head_y >= HEIGHT) return true;
	
	int snake_length = snake->length;
	for(int tile = 1; tile < snake_length; tile++)
	{
		if(head_x == snake->body[tile].x_pos && head_y == snake->body[tile].y_pos)
		{
			return true;
		}
	}

	return false;
}

void growSnake(Snake *snake, int old_tail_x, int old_tail_y)
{
	int new_tail_index = snake->length;
	snake->body[new_tail_index].x_pos = old_tail_x;
	snake->body[new_tail_index].y_pos = old_tail_y;
	snake->length++;
}

void initField(TileTypes field[ROWS][COLUMNS])
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			field[row][col] = EMPTY;
		}
	}
}

void clearField(TileTypes field[ROWS][COLUMNS])
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (field[row][col] != APPLE)
			{
				field[row][col] = EMPTY;
			}
		}
	}
}

void putApple(TileTypes field[ROWS][COLUMNS])
{
	int emptyTiles = 0;
	for (int row = 0; row < ROWS; row ++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if(field[row][col] == EMPTY) emptyTiles++;
		}
	}

	int apple_place = GetRandomValue(0, emptyTiles - 1);
	int apple_put = 0;

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if(field[row][col] == SNAKE) continue;
			if(apple_place == 0)
			{
				field[row][col] = APPLE;
				apple_put = 1;
				break;
			}
			apple_place--;
		}

		if (apple_put == 1) break; 
	}

}

void deleteOldGame(Snake **snake, TileTypes field[ROWS][COLUMNS])
{
	initField(field);
	if(*snake != 0) free(*snake);
	*snake = initSnake(field);
	putApple(field);
}

Texture2D getMainMenuTexture(void)
{
	Image mainMenuImg = LoadImage("./assets/Main_menu.png");
	ImageResize(&mainMenuImg, WIDTH, HEIGHT);
	Texture2D mainMenuTexture = LoadTextureFromImage(mainMenuImg);
	UnloadImage(mainMenuImg);
	return mainMenuTexture;
}

Texture2D getGameOverTexture(void)
{
	Image gameOverImg = LoadImage("./assets/Game_over.png");
	ImageResize(&gameOverImg, WIDTH, HEIGHT);
	Texture2D gameOverTexture = LoadTextureFromImage(gameOverImg);
	UnloadImage(gameOverImg);
	return gameOverTexture;
}

Button initButton(void)
{
	Button newGameButton;
	float button_width = WIDTH / 5;
	float button_height = HEIGHT / 5;
	float button_x = WIDTH / 2 - button_width / 2;
	float button_y = HEIGHT / 2 - button_height / 2;
	float hitbox_width = button_width / 2;
	float hitbox_height = button_height / 3;
       	float hitbox_x = button_x + button_x / 8;
	float hitbox_y = button_y + button_y / 6;	

	Image buttonImg = LoadImage("./assets/button.png");
	Image button_hoverImg = LoadImage("./assets/Button_hover.png");
	ImageResize(&buttonImg, button_width, button_height);
	ImageResize(&button_hoverImg, button_width, button_height);
	Texture2D button = LoadTextureFromImage(buttonImg);
	Texture2D button_hover = LoadTextureFromImage(button_hoverImg);
	UnloadImage(buttonImg);
	UnloadImage(button_hoverImg);

	newGameButton.button = button;
	newGameButton.button_hovered = button_hover;
	newGameButton.rect.x = button_x;
	newGameButton.rect.y = button_y;
	newGameButton.rect.width = button_width;
	newGameButton.rect.height = button_height;
	newGameButton.hitbox.x = hitbox_x;
	newGameButton.hitbox.y = hitbox_y;
	newGameButton.hitbox.width = hitbox_width;
	newGameButton.hitbox.height = hitbox_height;
	return newGameButton;
}

bool checkButtonColision(int mouse_x, int mouse_y, Button *newGameButton)
{
	float hitbox_x = newGameButton->hitbox.x;
	float hitbox_y = newGameButton->hitbox.y;
	float hitbox_width = newGameButton->hitbox.width;
	float hitbox_height = newGameButton->hitbox.height;

	if (mouse_x >= hitbox_x && mouse_x <= hitbox_x + hitbox_width && mouse_y >= hitbox_y && mouse_y <= hitbox_y + hitbox_height)
	{
		return true;
	}
	return false;
}

void startNewGame(int mouse_x, int mouse_y, Button *newGameButton, State *gameState, Snake **snake, TileTypes field[ROWS][COLUMNS])
{
	bool colision = checkButtonColision(mouse_x, mouse_y, newGameButton);
	bool mouse_click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	
	if(colision && mouse_click)
	{
		if(*gameState == GAME_OVER)
		{
			deleteOldGame(snake, field);
		}
		*gameState = PLAYING; 
	}
}
