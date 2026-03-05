#include "rendering.h"
#include "logic.h"
#include "raylib.h"


void drawMainMenu(void)
{
	DrawRectangle(BUTTON_X, BUTTON_Y, BUTTON_WIDTH, BUTTON_HEIGHT, BUTTON_COLOR);
	DrawText("NEW GAME", TEXT_X, TEXT_Y, FONT_SIZE, TEXT_COLOR);
}
