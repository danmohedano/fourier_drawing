/**
 * 29/07/2021
 * Module: data
 * -----------------------------------------------------------------------------
 * Authors:
 * - Daniel Mohedano <https://github.com/danmohedano>
 * -----------------------------------------------------------------------------
 * Module that manages the data needed for the program (mainly the drawing
 * vectors)
 */

#ifndef DATA_H
#define DATA_H

#include <cstdint>
#include <complex>

/**
 * Class that represents the drawing vectors of the application.
 * These vectors are of the form Cn*e^(n2PIit) with Cn being the initialization
 * constant calculated through the application of the Fourier transform
 */
class DrawingVector{
    public:
        DrawingVector(int16_t);
        std::complex<double> get(double);
        void set_const(double, double);
    private:
        int16_t index;
        std::complex<double> c;
};

#endif