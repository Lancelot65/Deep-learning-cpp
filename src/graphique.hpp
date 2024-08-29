#ifndef GRAPHIQUE_HPP
#define GRAPHIQUE_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

class Graph {
private:
    std::vector<double> x_data;
    std::vector<std::vector<double>> y_data;

    int windowWidth = 800;
    int windowHeight = 600;
    int margin = 50;

    std::vector<sf::Color> couleur {sf::Color::Blue, sf::Color::Red, sf::Color::Green};
    sf::Color bg;

    float mapYValueToPixel(double yValue, double minY, double maxY) {
        return windowHeight - margin - ((yValue - minY) / (maxY - minY)) * (windowHeight - 2 * margin);
    }

public:
    Graph(const std::vector<double>& x_data, const std::vector<std::vector<double>>& y_data, sf::Color bg = sf::Color(128,128,128));

    void render();
};

#endif