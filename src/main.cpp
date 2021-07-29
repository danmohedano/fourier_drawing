/**
 * 27/07/2021
 * Module: main
 * -----------------------------------------------------------------------------
 * Authors:
 * - Daniel Mohedano <https://github.com/danmohedano>
 * -----------------------------------------------------------------------------
 * Main module to execute the program.
 */

#include "../includes/config.h"
#include "../includes/data.h"
#include "../includes/computation.h"
#include <iostream>
#include <SDL2/SDL.h>


int main(void)
{
    SDL_Window* gWindow = NULL;
    SDL_Surface* gScreenSurface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize. Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else
    {
        //Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			return 1;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface( gWindow );
		}
    }

    std::cout << "Init correct\n";

    SDL_UpdateWindowSurface(gWindow);
    SDL_Delay(2000);


    //Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
    return 0;
}