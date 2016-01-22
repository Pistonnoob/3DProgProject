#include <SDL.h>
#include <iostream>

int main(int argc, char* args[])
{
#pragma region
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return -1;
	}
#pragma endregion initialize SDL
	
#pragma region
	//Variables for SDL-window
	int windowPosX = 200;					//The X-position of the window
	int windowPosY = 200;					//The Y-position of the window
	int windowWidth = 300;					//The width of the window
	int windowHeight = 400;					//The height of the window
	SDL_Window* window;
	window = SDL_CreateWindow("3dProg", windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
		return -1;
	}
#pragma endregion creating the window


	return 0;
}
