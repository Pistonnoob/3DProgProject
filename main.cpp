#include <SDL.h>
#include <iostream>

SDL_Window* window = nullptr;	//The first and main window of the application
SDL_Renderer* renderer = nullptr;//The renderer associated with the first/main window

int Initiate();//Initiate everything, returns 1 if success
int InitSDL();//Initiates the SDL of the programm
int CreateWindow();//Creates the main window
int CreateRenderer();//Creates the main window renderer
void setupRenderer();//Executes the renderer setup

void Update();//The logic loop
void Render();//The rendering

//Variables for SDL-window
const int WINDOW_POS_X = 200;					//The X-position of the window
const int WINDOW_POS_Y = 200;					//The Y-position of the window
const int WINDOW_WIDTH = 300;					//The width of the window
const int WINDOW_HEIGHT = 400;					//The height of the window

SDL_Color windowColor;//The first/main window color

int main(int argc, char* args[])
{

	if (!Initiate())
		return -1;

	bool loop = true;
	while (loop)
	{
		SDL_Event wEvent;
		while (SDL_PollEvent(&wEvent))
		{
			if (wEvent.type == SDL_QUIT)
			{
				loop = false;
			}
			else if (wEvent.type == SDL_KEYDOWN)
			{
				switch (wEvent.key.keysym.sym)
				{
				default:
					break;
				}
			}

			Update();
			Render();
		}
	}

	return 0;
}

int Initiate()
{

	if (InitSDL() == -1)
		return -1;

	windowColor = { 10, 100, 0, 255 };

	if (CreateWindow() == -1)
		return -1;

	if (CreateRenderer() == -1)
		return -1;

	setupRenderer();

	return 1;
}
int InitSDL()
{
	//Initiate SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << " Failed to initialize SDL : " << SDL_GetError() << std::endl;
		return -1;
	}
	return 0;
}
int CreateWindow()
{
	window = SDL_CreateWindow("3dProg", WINDOW_POS_X, WINDOW_POS_Y, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		std::cout << "Failed to create window : " << SDL_GetError() << std::endl;
		return -1;
	}
	return 1;
}
int CreateRenderer()
{
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		std::cout << "Failed to create renderer : " << SDL_GetError() << std::endl;
		return -1;
	}
	return 1;
}
void setupRenderer()
{
	if (SDL_RenderSetLogicalSize(renderer, WINDOW_WIDTH, WINDOW_HEIGHT))
	{
		std::cout << "Failed to set render size : " << SDL_GetError() << std::endl;
	}
	if (SDL_SetRenderDrawColor(renderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a))
	{
		std::cout << "Failed to set render color : " << SDL_GetError() << std::endl;
	}
}

void Update()
{
	//Currently no logic updates
}
void Render()
{
	//Clear the window and fill it with the render color
	SDL_SetRenderDrawColor(renderer, windowColor.r, windowColor.g, windowColor.b, windowColor.a);
	SDL_RenderClear(renderer);
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderDrawRect(renderer, &r);

	//Render the window
	SDL_RenderPresent(renderer);
}