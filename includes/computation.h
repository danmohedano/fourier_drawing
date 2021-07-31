/**
 * 29/07/2021
 * Module: computation
 * -----------------------------------------------------------------------------
 * Authors:
 * - Daniel Mohedano <https://github.com/danmohedano>
 * -----------------------------------------------------------------------------
 * Module responsible for the computation of the Fourier transform
 */
#ifndef COMPUTATION_H
#define COMPUTATION_H

#include "../includes/data.h"
#include <complex>
#include <vector>

/**
 * Function: compute
 * ----------------------------------------------------------------------------
 * Computes the n vectors requested to represent the function described by 
 * the points provided. The operation is made using the following integral:
 * Vector_n = Cn*e^(n*2*PI*i*t)
 * Cn = integral[0,1](f(t)*e^(-n*2*PI*i*t)*dt)
 * 
 * params:
 *  - n: number of vectors requested
 *  - points: function described by its points
 *  - dt: time step used for the integral
 *  
 * returns: vector of DrawingVectors
 */
std::vector<DrawingVector> compute(uint16_t n, std::vector<std::complex<double>> points, double dt);

/**
 * Function: integral
 * ----------------------------------------------------------------------------
 * Computes the integral for the initialization constant vector of index "index"
 *  
 * params:
 *  - index: index of the vector
 *  - points: function described by its points
 *  - dt: time step used for the integral
 *  
 * returns: DrawingVector with the result
 */
DrawingVector integral(int16_t index, std::vector<std::complex<double>> points, double dt);


#endif