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

double fRand(double fMin, double fMax) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(fMin, fMax);
    return dis(gen);
}

Matrice random(Shape shape, double min, double max)
{
    std::vector<std::vector<double>> output(shape.row, std::vector<double>(shape.column));
    for (std::vector<double> &vector : output)
    {
        for (double &value : vector)
        {
            value = fRand(min, max);
        }
        
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

Matrice matrice_exp(Matrice matrice)
{
    std::vector<std::vector<double>> output = matrice.get_matrice();
    for (std::vector<double> &vector : output)
    {
        for (double &value : vector)
        {
            value = exp(value);
        }
        
    }
    return Matrice(output);
}