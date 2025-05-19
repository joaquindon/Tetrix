#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp> // Necesario para sf::Vector2

// Definición de Position (asumo que es un alias para sf::Vector2i)
using Position = sf::Vector2i;

class Tablero
{
    std::vector<Position> tabla;
public:
    Tablero(unsigned char shape);

    bool caida(const std::vector<std::vector<unsigned char>>& matriz);

    void reset(unsigned char shape);
    void actualizarMatriz(std::vector<std::vector<unsigned char>>& matriz);
    std::vector<Position> get_tabla() const; // Añadido const para consistencia
};