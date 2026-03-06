#pragma once
#include "logic.h"
#define TEXTCOLOR RAYWHITE
#define BUTTON_WIDTH (WIDTH / 3)
#define BUTTON_HEIGHT (HEIGHT / 6)
#define BUTTON_X (WIDTH / 2 - BUTTON_WIDTH / 2)
#define BUTTON_Y (HEIGHT / 2 - BUTTON_HEIGHT / 2)
#define BUTTON_COLOR DARKGRAY
#define TEXT_X (WIDTH / 2 - BUTTON_WIDTH / 2 + FONT_SIZE / 2)
#define TEXT_Y (HEIGHT / 2 - FONT_SIZE / 2)
#define FONT_SIZE (BUTTON_HEIGHT / 2)
#define TEXT_COLOR RAYWHITE



void drawMainMenu(Texture2D *mainMenuTexture, Button *newGameButton); // drawing menu in NEW_GAME State; 
	

