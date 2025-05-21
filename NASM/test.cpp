#include <iostream>

extern "C" {
    bool collision(struct Position* tabla, int size, unsigned char* matriz, int ancho, int alto);
    void rotate_piece(unsigned char* matriz);
}

struct Position {
    int x;
    int y;
};

void get_positions_from_piece(unsigned char pieza[4][4], Position* tabla, int& count, int offsetX, int offsetY) {
    count = 0;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            if (pieza[y][x] != 0) {
                tabla[count].x = x + offsetX;
                tabla[count].y = y + offsetY;
                count++;
            }
        }
    }
}

int main() {
    unsigned char pieza[4][4] = {
        {1, 1, 1, 1},  // Línea horizontal arriba
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    // Tablero 10x20 vacío
    const int ancho = 10, alto = 20;
    unsigned char tablero[alto][ancho] = {0};

    // Bloque fijo para colisión en fila 19, columna 4
    tablero[19][4] = 1;

    Position tabla[16];  // máximo 16 bloques
    int size = 0;

    int offsetX = 3;
    int offsetY = 16;

    get_positions_from_piece(pieza, tabla, size, offsetX, offsetY);

    std::cout << "Intentando caer la pieza...\n";

    // NO incrementar offsetY en el while. Dejar que ASM modifique tabla
    while (!collision(tabla, size, &tablero[0][0], ancho, alto)) {
        std::cout << "La pieza cayó una posición\n";
        for (int i = 0; i < size; ++i)
            std::cout << "(" << tabla[i].x << "," << tabla[i].y << ") ";
        std::cout << "\n";
    }

    std::cout << "Colisión detectada, la pieza no puede caer más.\n";

    return 0;
}
