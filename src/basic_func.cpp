#include "basic_func.hpp"

Matrice ones(Shape shape)
{
    return Matrice(shape, 1);
}

Matrice zeros(Shape shape)
{
    return Matrice(shape, 0);
}

Matrice empty(Shape shape)
{
    return Matrice(std::vector<std::vector<double>>(shape.row, std::vector<double>(shape.column)));
}

Matrice arange(double start, double end, double step)
{
    std::vector<std::vector<double>> output(1, std::vector<double>());
    for (double i = start; i < end; i += step)
    {
        output[0].push_back(i);
    }
    return Matrice(output);
}

Matrice linspace(double start, double end, int num)
{
    std::vector<std::vector<double>> output(1, std::vector<double>());
    float step = (end - start) / float(num - 1);
    for (double i = 0; i < num; i++)
    {
        output[0].push_back(start + i * step);
    }
    return Matrice(output);
}

void print_vector(std::vector<double> vector)
{
    for (const auto& val : vector)
    {
        std::cout << val << " ";
    }
}