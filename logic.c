#include "raylib.h"
#include "logic.h"


Texture2D getMainMenuTexture(void)
{
	Image mainMenuImg = LoadImage("Main_menu.png");
	ImageResize(&mainMenuImg, WIDTH, HEIGHT);
	Texture2D mainMenuTexture = LoadTextureFromImage(mainMenuImg);
	UnloadImage(mainMenuImg);
	return mainMenuTexture;
}

Button initButton(void)
{
	Button newGameButton;
	float button_width = WIDTH / 5;
	float button_height = HEIGHT / 5;
	float button_x = WIDTH / 2 - button_width / 2;
	float button_y = HEIGHT / 2 - button_height / 2;

	Image buttonImg = LoadImage("button.png");
	Image button_hoverImg = LoadImage("Button_hover.png");
	ImageResize(&buttonImg, button_width, button_height);
	ImageResize(&button_hoverImg, button_width, button_height);
	Texture2D button = LoadTextureFromImage(buttonImg);
	Texture2D button_hover = LoadTextureFromImage(button_hoverImg);
	UnloadImage(buttonImg);
	UnloadImage(button_hoverImg);

	newGameButton.button = button;
	newGameButton.button_hovered = button_hover;
	newGameButton.rect.x = button_x;
	newGameButton.rect.y = button_y;
	newGameButton.rect.width = button_width;
	newGameButton.rect.height = button_height;
	return newGameButton;
}
