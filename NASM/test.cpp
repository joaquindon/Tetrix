#include <iostream>

// Supongamos que solo estamos probando la rotación de la pieza
extern "C" void rotate_piece(unsigned char* matriz);

int main() {
    // Crear una pieza simple
    unsigned char pieza[4][4] = {
        {1, 1, 1, 1},  // Línea horizontal
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    std::cout << "\n=-=-= Rotacion 1 =-=-=\n";

    // Rotar la pieza
    rotate_piece(reinterpret_cast<unsigned char*>(pieza));

    // Imprimir la pieza rotada
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (int)pieza[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=-=-= Rotacion 2 =-=-=\n";

    // Rotar la pieza
    rotate_piece(reinterpret_cast<unsigned char*>(pieza));

    // Imprimir la pieza rotada
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (int)pieza[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=-=-= Rotacion 3 =-=-=\n";

    // Rotar la pieza
    rotate_piece(reinterpret_cast<unsigned char*>(pieza));

    // Imprimir la pieza rotada
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (int)pieza[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=-=-= Rotacion 4 =-=-=\n";

    // Rotar la pieza
    rotate_piece(reinterpret_cast<unsigned char*>(pieza));

    // Imprimir la pieza rotada
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << (int)pieza[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=-=-= Fin Rotaciones =-=-=\n";

    return 0;
}
