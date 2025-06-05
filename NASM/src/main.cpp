#include <iostream>
#include <cstring>

constexpr int WIDTH = 10;
constexpr int HEIGHT = 20;
constexpr int BOARD_SIZE = WIDTH * HEIGHT;

extern "C" {
    extern void checkCollision();
    extern void moveOneLeft();
    extern void moveOneRight();
    extern void moveOneDown();
    extern void solidifyPiece();

    extern uint8_t boardState[BOARD_SIZE];
    extern uint8_t piecePos[4];
    extern uint8_t piecePivotPos;
    extern uint8_t boardColor;
}

// Implementación dummy de solidifyPiece
extern "C" void solidifyPiece() {
    std::cout << "Pieza solidificada (no puede bajar más)." << std::endl;
    for (int i = 0; i < 4; ++i) {
        boardState[piecePos[i]] = boardColor;
    }
}

// Muestra el tablero (simple)
void printBoard() {
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int idx = y * WIDTH + x;
            bool isPiece = false;
            for (int i = 0; i < 4; ++i) {
                if (piecePos[i] == idx) {
                    std::cout << 'X';
                    isPiece = true;
                    break;
                }
            }
            if (!isPiece)
                std::cout << (boardState[idx] ? '#' : '.');
        }
        std::cout << "\n";
    }
    std::cout << "========================\n";
}

int main() {
    std::memset(boardState, 0, sizeof(boardState));

    // --- Inicializa una pieza en la parte superior ---
    piecePos[0] = 4;
    piecePos[1] = 5;
    piecePos[2] = 14;
    piecePos[3] = 15;
    piecePivotPos = 5;

    std::cout << "Estado inicial:\n";
    printBoard();

    // --- Movimiento de prueba ---
    std::cout << "Mover a la izquierda:\n";
    moveOneLeft();
    printBoard();

    std::cout << "Mover a la derecha:\n";
    moveOneRight();
    printBoard();

    std::cout << "Mover hacia abajo:\n";
    moveOneDown();
    printBoard();

    std::cout << "Chequeando colisión:\n";
    checkCollision();  // Si hay colisión, se solidifica
    printBoard();

    return 0;
}
