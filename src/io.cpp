#include "../includes/io.h"
#include "../includes/config.h"
#include <cmath>
#include <iostream>

void drawLoop(SDL_Renderer *renderer, std::vector<DrawingVector> vectors){
    SDL_Event event;
    bool finished = false;
    SDL_Point drawing_points[int(1.0 / DT)], aux_point;
    double time = 0.0;

    SDL_RenderSetScale(renderer, SCALE, SCALE);

    // Drawing loop
    while (!finished){
        drawBackground(renderer);
        aux_point = drawVectors(renderer, vectors, time);
        if (time < 1.0){
            drawing_points[int(time / DT)].x = aux_point.x;
            drawing_points[int(time / DT)].y = aux_point.y;
        }

        //Draw points reached
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(renderer, drawing_points, std::min((time / DT) + 1, 1.0 / DT));

        SDL_RenderPresent(renderer);

        time += DT;
        std::cout << "Time: " << time << std::endl;

        while(SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT) finished = true;
        }

        SDL_Delay(DISPLAY_DELAY);
    }
}

SDL_Point drawVectors(SDL_Renderer *renderer, std::vector<DrawingVector> vectors, double time){
    SDL_Point vector_points[vectors.size() + 1];

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    //Obtain the points of the vectors (start and finish of each of them)
    vector_points[0] = {X_OFFSET, Y_OFFSET}; //Initial point 0,0

    for (int i = 1; i < (int)(vectors.size() + 1); ++i){
        vector_points[i].x = vector_points[i-1].x + (int)(vectors[i-1].get(time).real());
        vector_points[i].y = vector_points[i-1].y - (int)(vectors[i-1].get(time).imag());;
    }

    //Scale points to increase width of the line
    for (int i = 0; i < (int)(vectors.size() + 1); ++i){
        vector_points[i].x /= SCALE;
        vector_points[i].y /= SCALE;
    }

    //Represent the vectors as lines
    SDL_RenderDrawLines(renderer, vector_points, vectors.size() + 1);

    // Return last point
    return vector_points[vectors.size()];
}

void drawBackground(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

