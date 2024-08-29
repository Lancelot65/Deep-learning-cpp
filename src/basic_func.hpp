#ifndef BASIC_FUNC_HPP
#define BASIC_FUNC_HPP

#include <iostream>
#include <random>
#include "matrice.hpp"

Matrice ones(Shape shape);
Matrice zeros(Shape shape);
Matrice empty(Shape shape);
Matrice arange(double start, double end, double step);
Matrice linspace(double start, double end, int num = 50);
Matrice random(Shape shape, double min = -3, double max = 3);
Matrice matrice_exp(Matrice matrice);

void print_vector(std::vector<double> vector);

#endif