#include "../includes/data.h"
#include <math.h>

DrawingVector::DrawingVector(int16_t n){
    index = n;
}

/**
 * Function: get
 * ----------------------------------------------------------------------------
 * Returns a complex number with the coordinates pointed to by the vector in
 * moment t.
 * 
 * params:
 *  - t: moment in time
 * 
 * returns: coordinates pointed to by the vector
 */
std::complex<double> DrawingVector::get(double t){
    return c * std::polar(1.0, (double)(index * 2 * M_PI * t));
}

/**
 * Function: set_const
 * ----------------------------------------------------------------------------
 * Sets the initialization constant.
 * 
 * params:
 *  - re: real part of the constant
 *  - im: imaginary part of the constant
 */
void DrawingVector::set_const(double re, double im){
    c.real(re);
    c.imag(im);
}

