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
    SnakeTile *snake = malloc(START_SNAKE_SIZE * sizeof(SnakeTile));
    while (!WindowShouldClose())
    {
	// For Logic
	switch(gameState)
	{
		case NEW_GAME:
			//TODO
			break;
		case PLAYING:
			//TODO
			break;
		case GAME_OVER:
			//TODO
			break;	
	}
        BeginDrawing();
            ClearBackground(GREEN);
	    
	    // For Rendering 
	    switch(gameState)
	    {
		    case NEW_GAME:
			drawMainMenu(&mainMenuTexture, &newGameButton);
			break;
		    case PLAYING:
		    	//TODO
			break;
		    case GAME_OVER:
			//TODO
			break;	    
	    }
        EndDrawing();
    }

    CloseWindow();
    free(snake);
    UnloadTexture(mainMenuTexture);
    UnloadTexture(newGameButton.button);
    UnloadTexture(newGameButton.button_hovered);

    return 0;
}
