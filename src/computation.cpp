#include "../includes/computation.h"
#include <cmath>

DrawingVector integral(int16_t index, std::vector<std::complex<double>> points, double dt){
    std::complex<double> cn;
    DrawingVector v(index);
    double t = 0;

    for (std::complex<double> point : points){
        cn += (point * std::polar(1.0, (double)((-1) * index * 2 * M_PI * t)) * dt);
        t += dt;
    }

    v.set_const(cn.real(), cn.imag());
    return v;
}


std::vector<DrawingVector> compute(uint16_t n, std::vector<std::complex<double>> points, double dt){
    int16_t index;
    std::vector<DrawingVector> vectors;

    vectors[0] = integral(0, points, dt);

    for(uint16_t i = 1; i < n; ++i){
        index = ceil(i / 2) * pow(-1, i + 1); // step function 1, -1, 2, -2, 3, -3, ...
        vectors.push_back(integral(index, points, dt));
    }

    return vectors;
}