#include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.hpp"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(200, 400), "Teatrix");
    window.setFramerateLimit(60);

    // ============== CARGAR IMAGEN DE FONDO ==============
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("/home/joa/Descargas/background.jpg")) {
        cerr << "Error cargando imagen de fondo! Usando color sólido." << endl;
        // Si hay error, usaremos un color sólido como respaldo
    }
    Sprite background(backgroundTexture);
    
    // Escalar la imagen para que cubra toda la ventana
    Vector2u textureSize = backgroundTexture.getSize();
    Vector2u windowSize = window.getSize();
    float scaleX = (float)windowSize.x / textureSize.x;
    float scaleY = (float)windowSize.y / textureSize.y;
    background.setScale(scaleX, scaleY);
    // ===================================================

    // ================== MENÚ PRINCIPAL ==================
    Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")) {
        cerr << "Error cargando fuente" << endl;
        return 1;
    }

    Text titulo("Teatrix", font, 40);
    titulo.setPosition(40, 50);
    titulo.setFillColor(Color::Cyan);

    Text opciones[2];
    string textos[2] = {"Jugar", "Salir"};
    
    for (int i = 0; i < 2; ++i) {
        opciones[i].setFont(font);
        opciones[i].setString(textos[i]);
        opciones[i].setCharacterSize(30);
        opciones[i].setPosition(60 + (i * 5) , 150 + i * 50);
    }

    int opcionSeleccionada = 0;

    bool enMenu = true;
    while (enMenu && window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Down) {
                    opcionSeleccionada = (opcionSeleccionada + 1) % 2;
                } else if (event.key.code == Keyboard::Up) {
                    opcionSeleccionada = (opcionSeleccionada + 1) % 2;
                } else if (event.key.code == Keyboard::Enter) {
                    if (opcionSeleccionada == 0) {
                        enMenu = false; // Comenzar juego
                    } else {
                        window.close(); // Salir
                    }
                }
            }
        }

        // Actualizar colores de las opciones
        opciones[0].setFillColor(opcionSeleccionada == 0 ? Color::Green : Color::White);
        opciones[1].setFillColor(opcionSeleccionada == 1 ? Color::Red : Color::White);

        // Dibujar menú CON FONDO
        window.clear(Color(20, 20, 20)); // Color de respaldo
        
        // Dibujar fondo primero
        window.draw(background);
        
        // Luego los elementos del menú
        window.draw(titulo);
        for (const auto& opcion : opciones) {
            window.draw(opcion);
        }
        window.display();
    }
    // ===================================================

    // Si se seleccionó "Salir", terminar el programa
    if (!window.isOpen()) return 0;

    // ================== JUEGO PRINCIPAL ==================
    Board tablero;
    tablero.InstallParts();

    int right = 0;
    int left = 0;
    
    while(window.isOpen()) {
        Event event;
        while(window.pollEvent(event)) 
        {
            if(event.type == Event::Closed) 
            {
                window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            tablero.UpdateTimerLimit(10);
        } else {
            tablero.UpdateTimerLimit(30);
        }
        
        if (Keyboard::isKeyPressed(Keyboard::Right) && right == 0) {
            /* código para mover derecha */
        }
        
        if(tablero.UpdateBoard()) {
            if(!tablero.InstallParts()) {         
                cout << "Game over" << endl;
                window.close();   
            }
        }
        
        tablero.UpdateBoardColors();
        window.clear(Color(20, 20, 20));
        window.draw(tablero);
        window.display();
    }
    return 0;
}