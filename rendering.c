#include "rendering.h"
#include "logic.h"
#include "raylib.h"
#include <stdbool.h>


void drawMainMenu(int mouse_x, int mouse_y, Texture2D *mainMenuTexture, Button *newGameButton)
{
	float button_x = newGameButton->rect.x;
	float button_y = newGameButton->rect.y;
	
	bool colision = checkButtonColision(mouse_x, mouse_y, newGameButton);
	DrawTexture(*mainMenuTexture, 0, 0, WHITE);
	
	if (colision)
	{
		DrawTexture(newGameButton->button_hovered, button_x, button_y, WHITE);
	} else
	{
		DrawTexture(newGameButton->button, button_x, button_y, WHITE);
	}	
}

