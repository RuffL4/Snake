#include <stdlib.h>
#include "raylib.h"
#include "logic.h"
#include "rendering.h"


int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(FPS);

    Texture2D mainMenuTexture = getMainMenuTexture();
    Button newGameButton = initButton();

    State gameState = NEW_GAME;
    TileTypes field[ROWS][COLUMNS];
    Snake *snake = initSnake();
    while (!WindowShouldClose())
    {
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();
	// For Logic
	switch(gameState)
	{
		case NEW_GAME:
			startNewGame(mouse_x, mouse_y, &newGameButton, &gameState);
			break;
		case PLAYING:
			moveSnake(snake);
			break;
		case GAME_OVER:
			//TODO
			break;	
	}
        BeginDrawing();
            ClearBackground(BLACK);
	    
	    // For Rendering 
	    switch(gameState)
	    {
		    case NEW_GAME:
			drawMainMenu(mouse_x, mouse_y, &mainMenuTexture, &newGameButton);
			break;
		    case PLAYING:
			drawSnake(snake);
			break;
		    case GAME_OVER:
			//TODO
			break;	    
	    }
        EndDrawing();
    }

    CloseWindow();
    free(snake->body);
    free(snake);
    UnloadTexture(mainMenuTexture);
    UnloadTexture(newGameButton.button);
    UnloadTexture(newGameButton.button_hovered);

    return 0;
}
