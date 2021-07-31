/**
 * 30/07/2021
 * Module: io
 * -----------------------------------------------------------------------------
 * Authors:
 * - Daniel Mohedano <https://github.com/danmohedano>
 * -----------------------------------------------------------------------------
 * Module that manages the input and output of the program. Mainly, the display
 * of the vectors and points drawn.
 */

#ifndef IO_H
#define IO_H
#include <SDL2/SDL.h>
#include <vector>
#include <complex>
#include "../includes/data.h"

/**
 * Function: drawLoop
 * ----------------------------------------------------------------------------
 * Drawing loop that manages the animation of the vectors and points
 * 
 * params:
 *  - renderer: Renderer to display the image
 *  - vectors: DrawingVectors to draw
 */
void drawLoop(SDL_Renderer *renderer, std::vector<DrawingVector> vectors, std::vector<std::complex<double>> original_points);

/**
 * Function: drawVectors
 * ----------------------------------------------------------------------------
 * Draws the vectors provided using the renderer provided.
 * 
 * params:
 *  - renderer: Renderer to display the image
 *  - vectors: DrawingVectors to draw
 *  - time: moment in time 
 * 
 * returns: the position pointed to by the last vector (position is 
 *          scaled by SCALE)
 */
SDL_Point drawVectors(SDL_Renderer *renderer, std::vector<DrawingVector> vectors, double time);

/**
 * Function: drawBackground
 * ----------------------------------------------------------------------------
 * Draws the background
 * 
 * params:
 *  - renderer: Renderer to display the image
 */
void drawBackground(SDL_Renderer *renderer);

/**
 * Function: input
 * ----------------------------------------------------------------------------
 * Takes the input of the user to record the points of the drawing
 * 
 * params:
 *  - renderer: Renderer to display the image
 * 
 * returns: vector of the points recorded (as complex numbers)
 */
std::vector<std::complex<double>> input(SDL_Renderer *renderer);

#endif