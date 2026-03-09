#include "raylib.h"
#include "logic.h"
#include <stdlib.h>


Snake* initSnake()
{
	Snake *snake = malloc(sizeof(Snake));
	if(snake == NULL) return NULL;

	snake->body = malloc(START_SNAKE_SIZE * sizeof(SnakeTile));
	if(snake->body == NULL)
	{
		free(snake);
		return NULL;
	}
	
	snake->direction = LEFT;
	snake->length = START_SNAKE_SIZE;
	
	int snake_x = SNAKE_HEAD_START_X;
	int snake_y = SNAKE_HEAD_START_Y;

	for (int tile = 0; tile < START_SNAKE_SIZE; tile++)
	{
		snake->body[tile].x_pos = snake_x;
	       	snake->body[tile].y_pos = snake_y;
		snake_x += TILESIZE; 	
	}
	
	return snake;
}

void moveSnake(Snake *snake)
{
	findDirection(snake);
	int length = snake->length - 1;
	for (int tile = length; tile >= 0; tile--)
	{
		if (tile == 0)
		{
			switch(snake->direction)
			{
				case UP:
				 	snake->body->y_pos -= TILESIZE;
					break;
				case DOWN:
					snake->body->y_pos += TILESIZE;
					break;
				case RIGHT:
					snake->body->x_pos += TILESIZE;
					break;
				case LEFT:
					snake->body->x_pos -= TILESIZE;
					break;
			}
			break;

		}
		int next_tile = tile - 1;
		int next_x_pos = snake->body[next_tile].x_pos;
		int next_y_pos = snake->body[next_tile].y_pos;
		snake->body[tile].x_pos = next_x_pos;
		snake->body[tile].y_pos = next_y_pos;
	}
}

void findDirection(Snake *snake)
{
	Direction dir = snake->direction;
	if(IsKeyPressed(KEY_UP) && dir != DOWN) snake->direction = UP;
	else if(IsKeyPressed(KEY_DOWN) && dir != UP) snake->direction = DOWN;
	else if(IsKeyPressed(KEY_RIGHT) && dir != LEFT) snake->direction = RIGHT;
	else if(IsKeyPressed(KEY_LEFT) && dir != RIGHT) snake->direction = LEFT;
}


Texture2D getMainMenuTexture(void)
{
	Image mainMenuImg = LoadImage("Main_menu.png");
	ImageResize(&mainMenuImg, WIDTH, HEIGHT);
	Texture2D mainMenuTexture = LoadTextureFromImage(mainMenuImg);
	UnloadImage(mainMenuImg);
	return mainMenuTexture;
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

	Image buttonImg = LoadImage("button.png");
	Image button_hoverImg = LoadImage("Button_hover.png");
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

void startNewGame(int mouse_x, int mouse_y, Button *newGameButton, State *gameState)
{
	bool colision = checkButtonColision(mouse_x, mouse_y, newGameButton);
	bool mouse_click = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
	
	if(colision && mouse_click)
	{
		*gameState = PLAYING; 
	}
}
