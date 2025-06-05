#include <cstdint>

constexpr int WIDTH = 10;
constexpr int HEIGHT = 20;
constexpr int BOARD_SIZE = WIDTH * HEIGHT;

extern "C" {
    uint8_t boardState[BOARD_SIZE] = {0};
    uint8_t piecePos[4] = {0};
    uint8_t piecePivotPos = 0;
    uint8_t boardColor = 1;
}
