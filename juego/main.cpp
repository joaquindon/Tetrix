#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

using namespace std;
using namespace sf;


int main()
{
    Board tablero;
    RenderWindow window (VideoMode (200,400), "Teatrix");
    window.setFramerateLimit(60);
    while(window.isOpen() ) {
        Event event;
        while(window.pollEvent (event)) 
        {
            if(event.type==Event::Closed) 
            {
                window.close();
            }
        }
        tablero.UpdateBoardColors();
        window.clear(Color(20,20,20));
        window.draw(tablero);
        window.display();
    }
    return 0;
}