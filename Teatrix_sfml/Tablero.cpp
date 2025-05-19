#include "Tablero.hpp"

bool Tablero::caida(const std::vector<std::vector<unsigned char>>& matriz)
{
    // Verificar si podemos caer (no hemos llegado al fondo ni hay bloque debajo)
    for (const Position& pos : tabla) 
    {
        // Verificar si llegamos al fondo del tablero
        if (pos.y >= matriz.size() - 1) 
        {
            return true; // Devolver true (no se puede caer más)
        }

        // Verificar si hay un bloque debajo de nosotros
        if (matriz[pos.y + 1][pos.x] != 0) 
        {
            return true;
        }
    }

    // Si podemos caer, mover todas las piezas hacia abajo
    for (Position& pos : tabla)
    {
        pos.y++;
    }

    return false; // Devolver false (sí se pudo caer)
}

void Tablero::actualizarMatriz(std::vector<std::vector<unsigned char>>& matriz)
{
    // Primero limpiar la posición anterior s

    // Marcar las nuevas posiciones en la matriz
    for (const Position& pos : tabla)
    {
        // Verificar que la posición esté dentro de los límites
        if (pos.y >= 0 && pos.y < matriz.size() &&
            pos.x >= 0 && pos.x < matriz[0].size())
        {
            matriz[pos.y][pos.x] = 1; // 1 representa bloque ocupado
        }
    }
}

void Tablero::reset(unsigned char shape)
{
    // Limpiar el tablero actual
    tabla.clear();

    // Definir las formas de los tetrominós (I, J, L, O, S, T, Z)
    switch (shape)
    {
    default:
        // Forma por defecto (el cuadrado)
        tabla = { {4, 0}, {5, 0}, {4, 1}, {5, 1} };
        break;
    }
}