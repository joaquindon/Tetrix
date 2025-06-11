#include <iostream>
#include <SFML/Graphics.hpp>
#include <cstring>

class Board: public sf::Drawable 
{
    private:
        int board [20][10];
        sf::RectangleShape boardShapes [20][10];
    public:
        Board();
        void UpdateBoardColors();
        void draw(sf::RenderTarget&, sf::RenderStates) const;
};