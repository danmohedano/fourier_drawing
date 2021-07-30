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
#include "../includes/io.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>


int main(void)
{
    /*---------INITIALIZATION---------*/
    std::cout << "Initializing SDL2 Window...\n";

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize. Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    else
    {
        //Create window and renderer
		if(SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer) != 0)
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
			return 1;
        }
    }

    std::cout << "Initialization finished.\n";

    /*---------LOOP---------*/
    // Test 
    std::vector<std::complex<double>> points(4);
    points[0] = std::complex<double>(50.0, 0.0);
    points[1] = std::complex<double>(25.0, 25.0);
    points[2] = std::complex<double>(0.0, 0.0);
    points[3] = std::complex<double>(25.0, -25.0);

    std::vector<DrawingVector> vs = compute(2, points, DT);

    for (DrawingVector i : vs){
        i.print();
    }

    drawLoop(renderer, vs);

    /*---------CLEAN---------*/
    //Destroy renderer
    if (renderer){
        SDL_DestroyRenderer(renderer);
    }

    //Destroy window
	if (window){
        SDL_DestroyWindow(window);
    }

	//Quit SDL subsystems
	SDL_Quit();

    return 0;
}