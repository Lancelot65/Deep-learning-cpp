#include "matrice.hpp"

// Constructor definitions
Matrice::Matrice(Shape shape, double standard_value)
    : data(shape.row, std::vector<double>(shape.column, standard_value)), shape(shape) {}

Matrice::Matrice(const std::vector<std::vector<double>>& matrice_vector)
    : data(std::move(matrice_vector))
{
    shape.row = data.size();
    shape.column = data.empty() ? 0 : data[0].size();
}

Matrice::Matrice(const Matrice &matrice)
    : data(matrice.data), shape(matrice.shape) {}

std::vector<std::vector<double>>& Matrice::get_matrice()
{
    return data;
}

double& Matrice::operator()(int row, int column)
{
    if (check(row, column))
    {
        return data[row][column];
    }
    throw std::out_of_range("Index out of bounds");
}

const double& Matrice::operator()(int row, int column) const
{
    if (check(row, column))
    {
        return data[row][column];
    }
    throw std::out_of_range("Index out of bounds");
}

bool Matrice::check(int row, int column) const
{
    return row >= 0 && row < shape.row && column >= 0 && column < shape.column;
}

Matrice Matrice::operator+(double add) const
{
    std::vector<std::vector<double>> output = data;
    for (auto &vector : output)
    {
        for (auto &number : vector)
        {
            number += add;
        }
    }
    return Matrice(output);
}

void Matrice::operator+=(double add)
{
    for (auto &vector : data)
    {
        for (auto &number : vector)
        {
            number += add;
        }
    }
}

Matrice Matrice::operator-(double subtract) const
{
    std::vector<std::vector<double>> output = data;
    for (auto &vector : output)
    {
        for (auto &number : vector)
        {
            number -= subtract;
        }
    }
    return Matrice(output);
}

void Matrice::operator-=(double subtract)
{
    for (auto &vector : data)
    {
        for (auto &number : vector)
        {
            number -= subtract;
        }
    }
}

Matrice Matrice::operator*(double multiply) const
{
    std::vector<std::vector<double>> output = data;
    for (auto &vector : output)
    {
        for (auto &number : vector)
        {
            number *= multiply;
        }
    }
    return Matrice(output);
}

void Matrice::operator*=(double multiply)
{
    for (auto &vector : data)
    {
        for (auto &number : vector)
        {
            number *= multiply;
        }
    }
}

Matrice Matrice::operator/(double divide) const
{
    std::vector<std::vector<double>> output = data;
    for (auto &vector : output)
    {
        for (auto &number : vector)
        {
            number /= divide;
        }
    }
    return Matrice(output);
}

void Matrice::operator/=(double divide)
{
    for (auto &vector : data)
    {
        for (auto &number : vector)
        {
            number /= divide;
        }
    }
}

Matrice Matrice::operator+(const Matrice &matrice_bis) const
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    std::vector<std::vector<double>> output(shape.row, std::vector<double>(shape.column));
    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            output[i][j] = data[i][j] + matrice_bis.data[i][j];
        }
    }
    return Matrice(output);
}

void Matrice::operator+=(const Matrice &matrice_bis)
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            data[i][j] += matrice_bis.data[i][j];
        }
    }
}

Matrice Matrice::operator-(const Matrice &matrice_bis) const
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    std::vector<std::vector<double>> output(shape.row, std::vector<double>(shape.column));
    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            output[i][j] = data[i][j] - matrice_bis.data[i][j];
        }
    }
    return Matrice(output);
}

void Matrice::operator-=(const Matrice &matrice_bis)
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            data[i][j] -= matrice_bis.data[i][j];
        }
    }
}

Matrice Matrice::operator*(const Matrice &matrice_bis) const
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    std::vector<std::vector<double>> output(shape.row, std::vector<double>(shape.column));
    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            output[i][j] = data[i][j] * matrice_bis.data[i][j];
        }
    }
    return Matrice(output);
}

void Matrice::operator*=(const Matrice &matrice_bis)
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            data[i][j] *= matrice_bis.data[i][j];
        }
    }
}

Matrice Matrice::operator/(const Matrice &matrice_bis) const
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    std::vector<std::vector<double>> output(shape.row, std::vector<double>(shape.column));
    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            output[i][j] = data[i][j] / matrice_bis.data[i][j];
        }
    }
    return Matrice(output);
}

void Matrice::operator/=(const Matrice &matrice_bis)
{
    if (shape != matrice_bis.shape)
    {
        throw std::invalid_argument("Shapes are different");
    }

    for (size_t i = 0; i < shape.row; ++i)
    {
        for (size_t j = 0; j < shape.column; ++j)
        {
            data[i][j] /= matrice_bis.data[i][j];
        }
    }
}

Matrice Matrice::dot(const Matrice &matrice_bis) const
{
    if (shape.column != matrice_bis.shape.row)
    {
        throw std::invalid_argument("Matrix dimensions do not match for dot product.");
    }

    Shape result_shape = {shape.row, matrice_bis.shape.column};
    std::vector<std::vector<double>> result_data(result_shape.row, std::vector<double>(result_shape.column, 0.0));

    for (size_t i = 0; i < result_shape.row; ++i)
    {
        for (size_t j = 0; j < result_shape.column; ++j)
        {
            double sum = 0.0;
            for (size_t k = 0; k < shape.column; ++k)
            {
                sum += data[i][k] * matrice_bis.data[k][j];
            }
            result_data[i][j] = sum;
        }
    }

    return Matrice(result_data);
}

void Matrice::print() const
{
    std::cout << "[";
    for (size_t i = 0; i < shape.row; ++i)
    {
        std::cout << "[";
        for (size_t j = 0; j < shape.column; ++j)
        {
            std::cout << data[i][j];
            if (j != shape.column - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        if (i != shape.row - 1)
        {
            std::cout << ",\n";
        }
    }
    std::cout << "]" << std::endl;
}


Matrice operator+(double lhs, const Matrice& rhs) {
    std::vector<std::vector<double>> output = rhs.data;
    for (auto& row : output) {
        for (auto& element : row) {
            element = lhs + element;
        }
    }
    return Matrice(output);
}

Matrice operator-(double lhs, const Matrice& rhs) {
    std::vector<std::vector<double>> output = rhs.data;
    for (auto& row : output) {
        for (auto& element : row) {
            element = lhs - element;
        }
    }
    return Matrice(output);
}

Matrice operator*(double lhs, const Matrice& rhs) {
    std::vector<std::vector<double>> output = rhs.data;
    for (auto& row : output) {
        for (auto& element : row) {
            element = lhs * element;
        }
    }
    return Matrice(output);
}

Matrice operator/(double lhs, const Matrice& rhs) {
    std::vector<std::vector<double>> output = rhs.data;
    for (auto& row : output) {
        for (auto& element : row) {
            if (element == 0) {
                throw std::invalid_argument("Division by zero in matrix element");
            }
            element = lhs / element;
        }
    }
    return Matrice(output);
}