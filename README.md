Modular Snake Engine

A high-performance implementation of the classic Snake game written in C99, utilizing the Raylib library for rendering and input handling.
Features

    Modular Architecture: The codebase is strictly partitioned into game logic (logic.c), rendering (rendering.c), and the application entry point (main.c), communicating via clean header interfaces.

    State Management: Implements a robust state machine (NEW_GAME, PLAYING, GAME_OVER) to manage game transitions.

    Dynamic Memory: The snake's body is managed using dynamic array allocation (malloc and free).

    Collision Detection: Efficient algorithms for self-collision and wall-collision detection.

    Visuals: Features texture loading for backgrounds, snake segments (head/body), and food.

    Automated Build: Includes a Makefile for streamlined compilation on compatible systems.

Credits & Assets

    Programming: Developed by Ruslan Liashkevich.

    Visual Assets: All textures and graphical resources used in this project were generated using the Gemini generative AI model.

Installation and Build
Prerequisites

    C Compiler: GCC (recommended, supporting C99).

    Raylib: The Raylib development library must be installed on your system.

Compilation

The project includes a Makefile to automate the build process.

    Open a terminal in the project root directory.

    Run the make command:
    Bash

    make

This will compile the source files (main.c, logic.c, rendering.c) and create an executable named snake.
Running the Game

After successful compilation, execute the binary:
Bash

./snake

Controls

    Arrow Keys (Up, Down, Left, Right): Change the snake's direction. The logic prevents 180-degree turns.

    Space Bar: Resets the game to a new game state from the Game Over or Start screen.

Technical Implementation Details

    main.c (Orchestrator): Manages the application lifecycle, initializes Raylib, orchestrates the main game loop, and delegates input and state updates to the logic and rendering modules.

    logic.c / logic.h (The Engine):

        Defines core data structures like Vector, Game, and State.

        initGame: Handles manual heap allocation (malloc) for the snake array.

        reviewGame: The primary simulation loop. Handles movement, growth mechanics (score increases and food respawning), and death conditions.

        unloadGame: Ensures proper memory cleanup by calling free on dynamically allocated resources.

    rendering.c / rendering.h (The View):

        Separates visual output from game logic.

        LoadTextures: Loads visual assets from the resources/textures/ directory.

        DrawRender: Draws the game world, scoring, and UI overlays based on the current Game state struct.

        UnloadRender: Ensures textures are properly removed from GPU memory via UnloadTexture.
