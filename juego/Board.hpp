#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>
#include <time.h>
#include "Parts.hpp"

class Board: public sf::Drawable 
{
    private:
        int board [20][10];
        sf::RectangleShape boardShapes [20][10];

        Parts parts;

        sf::Color newPartColor;
        int indNewPart, indColorNewPart;
    public:
        Board();
        bool InstallParts();
        void UpdateBoardColors();
        void draw(sf::RenderTarget&, sf::RenderStates) const;
};