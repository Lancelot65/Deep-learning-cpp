#ifndef BASIC_FUNC_HPP
#define BASIC_FUNC_HPP

#include "matrice.hpp"

Matrice ones(Shape shape);
Matrice zeros(Shape shape);
Matrice empty(Shape shape);
Matrice arange(double start, double end, double step);
Matrice linspace(double start, double end, int num = 50);

void print_vector(std::vector<double> vector);

#endif