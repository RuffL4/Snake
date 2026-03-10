#pragma once
#include "logic.h"


void drawMainMenu(int mouse_x, int mouse_y, Texture2D *mainMenuTexture, Button *newGameButton); // drawing menu & button in NEW_GAME State; 	
void drawField(TileTypes field[ROWS][COLUMNS]); // drawing snake; 
