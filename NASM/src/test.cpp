#include <iostream>
#include <thread>
#include <chrono>

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

void print_board(const unsigned char tablero[][10], int alto, int ancho, 
                 const Position* piezaPos = nullptr, int piezaSize = 0) {
    for (int y = 0; y < alto; ++y) {
        for (int x = 0; x < ancho; ++x) {
            bool isPieceBlock = false;
            if (piezaPos) {
                for (int i = 0; i < piezaSize; ++i) {
                    if (piezaPos[i].x == x && piezaPos[i].y == y) {
                        isPieceBlock = true;
                        break;
                    }
                }
            }

            if (isPieceBlock) {
                std::cout << "@"; // Pieza en movimiento
            } else if (tablero[y][x] != 0) {
                std::cout << "#"; // Bloque fijo
            } else {
                std::cout << ".";
            }
        }
        std::cout << "\n";
    }
    std::cout << "----------------------\n";
}

/*
bool collision(Position* tabla, int size, unsigned char* matriz, int ancho, int alto) {
    for (int i = 0; i < size; ++i) {
        int x = tabla[i].x;
        int y = tabla[i].y;
        if (x < 0 || x >= ancho || y < 0 || y >= alto) {
            return true;  // fuera de tablero
        }
        if (matriz[y * ancho + x] != 0) {
            return true;  // colisión con bloque fijo
        }
    }
    return false; // sin colisión
}
*/


int main() {
    const int ancho = 10, alto = 20;
    unsigned char tablero[alto][ancho] = {0};

    // Bloque fijo para probar colisión
    tablero[19][4] = 1;

    unsigned char pieza[4][4] = {
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    Position tabla[16];
    int size = 0;

    int offsetX = 3;
    int offsetY = 0;

    while (true) {
        // Calculamos posiciones de la pieza en la siguiente fila (descenso)
        get_positions_from_piece(pieza, tabla, size, offsetX, offsetY + 1);

        // Chequeamos colisión en la posición próxima
        bool col = collision(tabla, size, &tablero[0][0], ancho, alto);

        if (col) {
            // Colisión: fijar la pieza en la posición actual (no bajarla)
            get_positions_from_piece(pieza, tabla, size, offsetX, offsetY);
            for (int i = 0; i < size; ++i) {
                int x = tabla[i].x;
                int y = tabla[i].y;
                tablero[y][x] = 1;
            }

            // Imprimir tablero final con pieza fija
            print_board(tablero, alto, ancho);

            std::cout << "Pieza fijada. Reiniciando posición...\n";

            // Reiniciamos la pieza arriba
            offsetX = 3;
            offsetY = 0;

            // Opcional: salir o seguir con otra pieza
            break;
        } else {
            // No colisión, bajar la pieza
            offsetY++;

            // Imprimir tablero con pieza en movimiento
            get_positions_from_piece(pieza, tabla, size, offsetX, offsetY);
            print_board(tablero, alto, ancho, tabla, size);

            // Esperar un poco para ver la animación
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
    }

    return 0;
}
