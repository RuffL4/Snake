#pragma once
#include "logic.h"


void drawMenu(int mouse_x, int mouse_y, Texture2D *menuTexture, Button *newGameButton); // drawing main menu or game over & button in NEW_GAME or GAME_OVER State; 	
void drawField(TileTypes field[ROWS][COLUMNS]); // drawing snake; 
