#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>
#include "Tablero.hpp"

int main()
{
    // Constantes del juego
    const unsigned char COLS = 10;
    const unsigned char ROWS = 20;
    const unsigned int CELL_SIZE = 20;
    const float INITIAL_DELAY = 0.5f;

    // Inicialización de la ventana
    sf::RenderWindow window(sf::VideoMode({COLS * CELL_SIZE, ROWS * CELL_SIZE}), "Tetris SFML");
    window.setFramerateLimit(60);

    // Matriz del juego (columnas x filas)
    std::vector<std::vector<unsigned char>> matrix(ROWS, std::vector<unsigned char>(COLS, 0));
    
    // Reloj para controlar la caída automática
    sf::Clock clock;
    float timer = 0;
    float delay = INITIAL_DELAY;

    // Crear e inicializar el tablero con una pieza aleatoria
    Tablero tablero('I'); // Comienza con la pieza I

    while (window.isOpen())
    {
        // Manejo del tiempo para la caída automática
        float time = clock.restart().asSeconds();
        timer += time;

        // Procesamiento de eventos
        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            // Controles del teclado
            if (const auto* keyEvent = event->getIf<sf::Event::KeyPressed>())
            {
                switch (keyEvent->key)
                {
                    case sf::Keyboard::Left:
                        // Mover izquierda (nos falta lógica)
                        break;
                    case sf::Keyboard::Right:
                        // Mover derecha (nos falta lógica)
                        break;
                    case sf::Keyboard::Down:
                        // Acelerar caída
                        delay = 0.05f;
                        break;
                    case sf::Keyboard::Up:
                        // Rotar pieza (nos falta lógica)
                        break;
                    case sf::Keyboard::Space:
                        // Caída instantánea (nos falta lógica)
                        break;
                    default:
                        break;
                }
            }
        }

        // Lógica de caída automática
        if (timer > delay)
        {
            timer = 0;
            if (!tablero.caida(matrix))
            {
                // La pieza no pudo caer más, actualizar matriz
                tablero.actualizarMatriz(matrix);
                // Crear nueva pieza
                char shapes[] = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};
                tablero.reset(shapes[rand() % 7]);
            }
            delay = INITIAL_DELAY; // Resetear delay después de acelerar
        }

        // Dibujado
        window.clear(sf::Color(40, 40, 40));
        
        // Dibujar la cuadrícula
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));

        // Dibujar la matriz
        for (unsigned char row = 0; row < ROWS; row++)
        {
            for (unsigned char col = 0; col < COLS; col++)
            {
                cell.setPosition(static_cast<float>(CELL_SIZE * col), 
                                static_cast<float>(CELL_SIZE * row));

                if (matrix[row][col])
                    cell.setFillColor(sf::Color(255, 0, 0)); // Rojo para bloques fijos
                else
                    cell.setFillColor(sf::Color(10, 10, 10)); // Gris para espacio vacío

                window.draw(cell);
            }
        }
        window.display();
    }

    return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
