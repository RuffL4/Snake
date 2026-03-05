#include <stdlib.h>
#include "raylib.h"
#include "logic.h"
#include "rendering.h"


int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Snake");
    SetTargetFPS(FPS);

    state gameState = NEW_GAME;
    tileTypes field[ROWS][COLUMNS];
    snakeTile *snake = malloc(START_SNAKE_SIZE * sizeof(snakeTile));
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
			drawMainMenu();
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

    return 0;
}
