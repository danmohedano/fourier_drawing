#include "../includes/io.h"
#include "../includes/config.h"
#include <cmath>
#include <iostream>

void drawLoop(SDL_Renderer *renderer, std::vector<DrawingVector> vectors, std::vector<std::complex<double>> original_points){
    SDL_Event event;
    bool finished = false;
    SDL_Point drawing_points[int(1.0 / DT)], aux_point, original[(int)(original_points.size())];
    double time = 0.0;

    //SDL_RenderSetScale(renderer, SCALE, SCALE);

    //Convert original points to SDL_Points
    for (int i = 0; i < (int)(original_points.size()); ++i){
        original[i].x = (int)(original_points[i].real()) + X_OFFSET;
        original[i].y = (int)(original_points[i].imag()) * (-1) + Y_OFFSET;
    }

    // Drawing loop
    while (!finished){
        drawBackground(renderer);
        aux_point = drawVectors(renderer, vectors, time);
        if (time < 1.0){
            drawing_points[int(time / DT)].x = aux_point.x;
            drawing_points[int(time / DT)].y = aux_point.y;
        }

        //Draw original drawing recorded
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(renderer, original, original_points.size());

        //Draw points reached
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoints(renderer, drawing_points, std::min((time / DT) + 1, 1.0 / DT));

        SDL_RenderPresent(renderer);

        time += DT;
        std::cout << "Displaying t = " << time << std::endl;

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
    /*for (int i = 0; i < (int)(vectors.size() + 1); ++i){
        vector_points[i].x /= SCALE;
        vector_points[i].y /= SCALE;
    }*/

    //Represent the vectors as lines
    SDL_RenderDrawLines(renderer, vector_points, vectors.size() + 1);

    // Return last point
    return vector_points[vectors.size()];
}

void drawBackground(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
}

std::vector<std::complex<double>> input(SDL_Renderer *renderer){
    int mouse_x, mouse_y;
    std::vector<std::complex<double>> points;
    double t = 0.0;

    //Setup window
    drawBackground(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, SDL_ALPHA_OPAQUE);

    while (t < RECORDING_TIME_S){
        // Get mouse coordinates
        SDL_PumpEvents();
        SDL_GetMouseState(&mouse_x, &mouse_y);

        //Save the data
        points.push_back(std::complex<double>((1.0)*(mouse_x - X_OFFSET), (-1.0)*(mouse_y - Y_OFFSET)));

        //Represent the point in the window
        SDL_RenderDrawPoint(renderer, mouse_x, mouse_y);
        SDL_RenderPresent(renderer);
        
        t += RECORDING_DT_S;
        std::cout << "Input Time: " << t << "/" << RECORDING_TIME_S << std::endl;
        SDL_Delay(RECORDING_DT_MS);
    }

    return points;
}

