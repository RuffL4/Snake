#include <stdlib.h>
#include "raylib.h"
#include "logic.h"
#include "rendering.h"


int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(FPS);
    SetRandomSeed(1);

    Texture2D mainMenuTexture = getMainMenuTexture();
    Texture2D gameOverTexture = getGameOverTexture();
    Button newGameButton = initButton();

    State gameState = NEW_GAME;
    TileTypes field[ROWS][COLUMNS];
    initField(field);
    Snake *snake = initSnake(field);
    putApple(field);
    
    float timeCounter = 0.0f;

    while (!WindowShouldClose())
    {
	int mouse_x = GetMouseX();
	int mouse_y = GetMouseY();
	// For Logic
	switch(gameState)
	{
		case NEW_GAME:
			startNewGame(mouse_x, mouse_y, &newGameButton, &gameState, &snake, field);
			break;
		case PLAYING:
			timeCounter += GetFrameTime();

			findDirection(snake);
			if(timeCounter >= MAX_FRAME_TIME)
			{
				moveSnake(snake, field, &gameState);
				timeCounter = 0;
			}
			break;
		case GAME_OVER:
			startNewGame(mouse_x, mouse_y, &newGameButton, &gameState, &snake, field);
			break;	
	}
        BeginDrawing();
            ClearBackground(BLACK);
	    
	    // For Rendering 
	    switch(gameState)
	    {
		    case NEW_GAME:
			drawMenu(mouse_x, mouse_y, &mainMenuTexture, &newGameButton);
			break;
		    case PLAYING:
			drawField(field);
			break;
		    case GAME_OVER:
			drawMenu(mouse_x, mouse_y, &gameOverTexture, &newGameButton);
			break;	    
	    }
        EndDrawing();
    }

    free(snake);
    UnloadTexture(mainMenuTexture);
    UnloadTexture(gameOverTexture);
    UnloadTexture(newGameButton.button);
    UnloadTexture(newGameButton.button_hovered);
    CloseWindow();
    
    return 0;

}
