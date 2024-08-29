#include <iostream>
#include <vector>
#include <random>

#include "matrice.hpp"
#include "basic_func.hpp"

class Layer
{
private:
    Matrice weight;
    Matrice bias;
public:
    Layer(int input_len, int nbr_noyau) : weight(random(Shape(input_len, nbr_noyau))), bias(random(Shape(1, nbr_noyau))) {}

    Matrice activation(Matrice z)
    {
        return 1 / (1 + matrice_exp(z));
    }

    Matrice calcul(Matrice input)
    {
        return this->activation(input.dot(this->weight) + this->bias);
    }

    Matrice get_matrice()
    {
        return this->weight;
    }
};

class reseau_neuronne
{
private:
    std::vector<Layer> layers;
public:
    reseau_neuronne(std::vector<int> layer_nbr)// {nbr_inpur, nbr_neuron, nbr_neuron, ..., nbr_neuron}
    {
        for (size_t i = 1; i < layer_nbr.size(); i++)
        {
            layers.push_back(Layer(layer_nbr[i - 1], layer_nbr[i]));
        }
    }

    void print()
    {
        for (auto &&layer : layers)
        {
            layer.get_matrice().print();
            std::cout << std::endl;
        }
        
    }

    Matrice calcul(Matrice input)
    {
        Matrice output(input);
        for (auto &&layer : layers)
        {
            output = layer.calcul(output);
        }
        return output;
        
    }
};


int main()
{
    reseau_neuronne test({4,6,2});
    test.print();
    return 0;
}
