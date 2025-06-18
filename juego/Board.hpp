#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Parts.hpp"

// Declaración de funciones NASM
extern "C" {
    void MoveRight(int* board, int* indX);
    void MoveLeft(int* board, int* indX);
    bool UpdateBoardASM(int* board, int* timer, int timerLimit, int* indY, int indColorNewPart);
}

class Board : public sf::Drawable
{
private:
    int timer = 0;
    int indX, indY;
    int board[20][10];
    int timerLimit = 30;
    int indNewPart, indColorNewPart;

    Parts parts;
    sf::Color newPartColor;
    sf::RectangleShape boardShapes[20][10];

public:
    Board();
    bool InstallParts();
    bool UpdateBoard();
    void Left();
    void Right();
    void UpdateBoardColors();
    void UpdateTimerLimit(int velocidad);
    void draw(sf::RenderTarget&, sf::RenderStates) const;
};
