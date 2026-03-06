#include "rendering.h"
#include "logic.h"
#include "raylib.h"


void drawMainMenu(Texture2D *mainMenuTexture, Button *newGameButton)
{
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();
	float button_x = newGameButton->rect.x;
	float button_y = newGameButton->rect.y;
	float button_width = newGameButton->rect.width;
	float button_height = newGameButton->rect.height;
	
	
	DrawTexture(*mainMenuTexture, 0, 0, WHITE);
	
	if (mouse_x >= button_x && mouse_x <= button_x + button_width && mouse_y >= button_y && mouse_y <= button_y + button_height)
	{
		DrawTexture(newGameButton->button_hovered, button_x, button_y, WHITE);
	} else
	{
		DrawTexture(newGameButton->button, button_x, button_y, WHITE);
	}	
}
