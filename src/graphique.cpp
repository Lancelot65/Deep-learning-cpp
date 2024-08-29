#include "graphique.hpp"

Graph::Graph(const std::vector<double>& x_data, const std::vector<std::vector<double>>& y_data, sf::Color bg) : 
    x_data(x_data), 
    y_data(y_data), 
    bg(bg) {this->render();}

void Graph::render()
{
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Graph with SFML");

    std::vector<double> minvector;
    std::vector<double> maxvector;
    for (auto &vector : this->y_data)
    {
        minvector.push_back(*std::min_element(vector.begin(), vector.end()));
        maxvector.push_back(*std::max_element(vector.begin(), vector.end()));   
    }

    double minYValue = *std::min_element(minvector.begin(), minvector.end());
    double maxYValue = *std::max_element(maxvector.begin(), maxvector.end());   
    
    float pointSpacing = (windowWidth - 2 * margin) / static_cast<float>(x_data.size() - 1);

    sf::Font font;
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
        std::cerr << "Error loading font arial.ttf" << std::endl;
        return;
    }

    std::vector<sf::Text> xLabels, yLabels;

    int numYLabels = 5;
    for (int i = 0; i <= numYLabels; ++i) {
        float y = margin + i * (windowHeight - 2 * margin) / numYLabels;
        double value = minYValue + (maxYValue - minYValue) * (1.0 - i / static_cast<double>(numYLabels));
        sf::Text label(std::to_string(static_cast<int>(value)), font, 12);
        label.setFillColor(sf::Color::Black);
        label.setPosition(margin - 30, y - 10);
        yLabels.push_back(label);
    }

    size_t maxXLabels = 10;
    size_t xLabelInterval = (x_data.size() <= maxXLabels) ? 1 : (x_data.size() / maxXLabels);

    for (size_t i = 0; i < x_data.size(); i += xLabelInterval) {
        float x = margin + i * pointSpacing;
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << this->x_data[i];
        sf::Text label(oss.str(), font, 12);
        label.setFillColor(sf::Color::Black);
        label.setPosition(x - 5, windowHeight - margin + 5);
        xLabels.push_back(label);
    }

    int count = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(bg);

        count = 0;
        for (auto &vector : this->y_data)
        {
            for (size_t i = 0; i < x_data.size(); ++i) {
                float x = margin + i * pointSpacing;
                float y = mapYValueToPixel(vector[i], minYValue, maxYValue);

                if (i > 0) {
                    float prevX = margin + (i - 1) * pointSpacing;
                    float prevY = mapYValueToPixel(vector[i - 1], minYValue, maxYValue);
                    sf::Vertex line[] = {
                        sf::Vertex(sf::Vector2f(prevX, prevY), this->couleur[count]),
                        sf::Vertex(sf::Vector2f(x, y), this->couleur[count])
                    };
                    window.draw(line, 2, sf::Lines);
                }
            }
            count++;
        }

        sf::Vertex x_axis[] = {
            sf::Vertex(sf::Vector2f(margin, windowHeight - margin), sf::Color::Black),
            sf::Vertex(sf::Vector2f(windowWidth - margin, windowHeight - margin), sf::Color::Black)
        };
        window.draw(x_axis, 2, sf::Lines);

        sf::Vertex y_axis[] = {
            sf::Vertex(sf::Vector2f(margin, margin), sf::Color::Black),
            sf::Vertex(sf::Vector2f(margin, windowHeight - margin), sf::Color::Black)
        };
        window.draw(y_axis, 2, sf::Lines);

        for (const auto& label : xLabels)
            window.draw(label);
        for (const auto& label : yLabels)
            window.draw(label);

        window.display();
    }
}
