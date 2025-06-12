#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int width = 1000;
const int height = 200;
const int rectHeight = 50;

void drawKantor(float x1, float width, int n, SDL_Renderer *renderer)
{
	if(n == 0)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black
		SDL_FRect r{x1, 0, width, rectHeight};
		SDL_RenderFillRectF(renderer, &r); // Draw a filled rectangle
		return;
	}

	float part = width/3;

	//first 1/3
	drawKantor(x1, part, n-1, renderer);

	//second 1/3
	//do nothing

	//third 1/3
	drawKantor(x1+part*2, part, n-1, renderer);
}

int main(int argc, char* argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
        cout << "Failed to initialize SDL: " << SDL_GetError();
        return 1;
    }

    // Create a window
    SDL_Window *window = SDL_CreateWindow("Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		 width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
	{
        cout << "Failed to create window: " << SDL_GetError();
        SDL_Quit();
        return 1;
    }

	SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if (!renderer)
	{
		cout << "Error creating renderer: " << SDL_GetError();
		return false;
	}

	if(argc == 2)
	{
		int iterations = stoi(argv[1]);
		bool loop = true;
		while(loop)
		{

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);

			drawKantor(5,width-10,iterations,renderer);

			SDL_RenderPresent(renderer);

			SDL_Event e;
			while(SDL_PollEvent(&e) != 0 )
			{
				if(e.type == SDL_QUIT)
				{
					loop = false;
				}
			}
			SDL_Delay(100);
		}
	}
	else
	{
		bool loop = true;
		for(int i = 0; loop; i++)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderClear(renderer);

			drawKantor(5,width-10, i, renderer);

			SDL_RenderPresent(renderer);

			SDL_Event e;
			while(SDL_PollEvent(&e) != 0 )
			{
				if(e.type == SDL_QUIT)
				{
					loop = false;
				}
			}
			SDL_Delay(1000);
		}
	}

    // Clean up
	SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
