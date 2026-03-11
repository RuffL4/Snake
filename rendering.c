#include "rendering.h"
#include "logic.h"
#include "raylib.h"
#include <stdbool.h>


void drawMenu(int mouse_x, int mouse_y, Texture2D *menuTexture, Button *newGameButton)
{
	float button_x = newGameButton->rect.x;
	float button_y = newGameButton->rect.y;
	
	bool colision = checkButtonColision(mouse_x, mouse_y, newGameButton);
	DrawTexture(*menuTexture, 0, 0, WHITE);
	
	if (colision)
	{
		DrawTexture(newGameButton->button_hovered, button_x, button_y, WHITE);
	} else
	{
		DrawTexture(newGameButton->button, button_x, button_y, WHITE);
	}	
}

void drawField(TileTypes field[ROWS][COLUMNS])
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLUMNS; col++)
		{
			if (field[row][col] == APPLE)
			{
				int apple_x = col * TILESIZE;
				int apple_y = row * TILESIZE;
				DrawRectangle(apple_x, apple_y, TILESIZE, TILESIZE, APPLE_COLOR);

			} else if (field[row][col] == SNAKE)
			{
				int snake_x = col * TILESIZE;
				int snake_y = row * TILESIZE;
				DrawRectangle(snake_x, snake_y, TILESIZE, TILESIZE, SNAKE_COLOR);
			}

		}
	}
}
