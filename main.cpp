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
	
	//Variables for SDL-window
	int windowPosX = 200;					//The X-position of the window
	int windowPosY = 200;					//The Y-position of the window
	int windowWidth = 300;					//The width of the window
	int windowHeight = 400;					//The height of the window
	SDL_Window* window;
	SDL_Renderer* renderer;
#pragma region
	window = SDL_CreateWindow("3dProg", windowPosX, windowPosY, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
		return -1;
	}
#pragma endregion creating the window
#pragma region
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError() << std::endl;
		return -1;
	}
	if (SDL_RenderSetLogicalSize(renderer, windowWidth, windowHeight))
	{
		std::cout << "Failed to set render size : " << SDL_GetError() << std::endl;
	}
	if (SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255))
	{
		std::cout << "Failed to set render color : " << SDL_GetError() << std::endl;
	}
#pragma endregion creating renderer

	//Clear the window and fill it with the render color
	SDL_RenderClear(renderer);
	//Render the window
	SDL_RenderPresent(renderer);
	SDL_Delay(2000);
	return 0;
}
