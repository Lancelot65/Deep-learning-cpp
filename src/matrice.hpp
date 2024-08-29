#ifndef MATRICE_HPP
#define MATRICE_HPP

#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

struct Shape {
    int row;
    int column;

    Shape() : row(0), column(0) {} 
    Shape(int row, int column) : row(row), column(column) {}
    Shape(const Shape& shape)  : row(shape.row), column(shape.column) {}

    bool operator!=(const Shape& autre) const {
        return (row != autre.row) || (column != autre.column);
    }

    bool operator==(const Shape& autre) const {
        return (row == autre.row) && (column == autre.column);
    }
};

class Matrice {
private:
    std::vector<std::vector<double>> data; // Use nested vector for matrix data
    Shape shape;

public:
    Matrice(Shape shape, double standard_value = 0.0); 
    Matrice(const std::vector<std::vector<double>>& matrice_vector); 
    Matrice(const Matrice& matrice); // Copy constructor

    std::vector<std::vector<double>>& get_matrice();

    double& operator()(int row, int column);

    const double& operator()(int row, int column) const;

    bool check(int row, int column) const;

    Matrice& operator=(const Matrice& matrice) = default; // Default assignment operator

    Matrice operator+(double add) const;
    void operator+=(double add);
    Matrice operator-(double add) const;
    void operator-=(double add);
    Matrice operator*(double add) const;
    void operator*=(double add);
    Matrice operator/(double add) const;
    void operator/=(double add);

    Matrice operator+(const Matrice& matrice_bis) const;
    void operator+=(const Matrice& matrice_bis);
    Matrice operator-(const Matrice& matrice_bis) const;
    void operator-=(const Matrice& matrice_bis);
    Matrice operator*(const Matrice& matrice_bis) const;
    void operator*=(const Matrice& matrice_bis);
    Matrice operator/(const Matrice& matrice_bis) const;
    void operator/=(const Matrice& matrice_bis);

    friend Matrice operator+(double lhs, const Matrice& rhs);
    friend Matrice operator-(double lhs, const Matrice& rhs);
    friend Matrice operator*(double lhs, const Matrice& rhs);
    friend Matrice operator/(double lhs, const Matrice& rhs);

    Matrice dot(const Matrice& matrice_bis) const;

    void print() const;
};

#endif
