#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

const int width = 1000;
const int height = 200;
const int rectHeight = 50;

void drawKantor(int x1, int width, int n, SDL_Renderer *renderer)
{
	if(n == 0)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black
		SDL_Rect r{x1, 0, width, rectHeight};
		SDL_RenderFillRect(renderer, &r); // Draw a filled rectangle
		return;
	}

	int part = width/3;
	if(part == 0)
		return;

	drawKantor(x1, part, n-1, renderer);//first 1/3

	//second 1/3
	SDL_SetRenderDrawColor(renderer, 255,255,255,255);//white
	SDL_Rect r{x1+part, 0, part, rectHeight};
	SDL_RenderFillRect(renderer, &r); // Draw a filled rectangle

	//third 1/3
	drawKantor(x1+part*2, part, n-1, renderer);
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
        cout << "Failed to initialize SDL: " <<  SDL_GetError();
        return 1;
    }

	
    // Create a window
    SDL_Window *window = SDL_CreateWindow( "Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );

    if (window == NULL)
	{
        cout << "Failed to create window: " <<  SDL_GetError();
        SDL_Quit();
        return 1;
    }

	SDL_Renderer *renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
	if (!renderer) {
		cout << "Error creating renderer: " << SDL_GetError() << endl;
		return false;
	}

	int iterations = 3;
	if(argc == 2)
		iterations = stoi(argv[1]);

	bool loop = true;
	while(loop)
	{
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderClear(renderer);

		drawKantor(0,width,iterations,renderer);
		
		SDL_RenderPresent(renderer);

		SDL_Event e;
		while(SDL_PollEvent(&e) != 0 )
		{
			if(e.type == SDL_QUIT)
				loop = false;
		}
		SDL_Delay(100);
	}

    // Clean up
	SDL_DestroyRenderer( renderer );
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}