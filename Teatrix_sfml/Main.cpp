#include <SFML/Graphics.hpp>
#include <optional>
#include <vector>
#include <array>
#include <ctime>
#include <cstdlib>
#include "Grid.hpp"

int main() {
    // Configuración inicial
    const unsigned int COLS = 10;
    const unsigned int ROWS = 20;
    const unsigned int CELL_SIZE = 30;
    const float FALL_DELAY = 1.5f;

    std::srand(static_cast<unsigned>(std::time(nullptr)));
    sf::RenderWindow window(sf::VideoMode({ COLS * CELL_SIZE, ROWS * CELL_SIZE }), "Tetris 3.0");
    window.setFramerateLimit(60);

    std::vector<std::vector<unsigned char>> matrix(ROWS, std::vector<unsigned char>(COLS, 0));
    sf::Clock clock;
    float timer = 0;
  
    const std::array SHAPES = 
    {
        Tablero::FormaPieza::I,
        Tablero::FormaPieza::J,
        Tablero::FormaPieza::L,
        Tablero::FormaPieza::O,
        Tablero::FormaPieza::S,
        Tablero::FormaPieza::T,
        Tablero::FormaPieza::Z
    }; 

    Tablero tablero(SHAPES[std::rand() % SHAPES.size()]);

    // Colores
    constexpr auto BACKGROUND = sf::Color(40, 40, 40);
    constexpr auto FILLED = sf::Color(255, 50, 50);
    constexpr auto CURRENT_PIECE = sf::Color(50, 255, 50);

    while (window.isOpen()) {
        const float deltaTime = clock.restart().asSeconds();
        timer += deltaTime;

        // Manejo de eventos actualizado
        // Manejo de eventos actualizado
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        

            if (event->is<sf::Event::KeyPressed>()) {
                const auto& keyEvent = event->getIf<sf::Event::KeyPressed>();
                switch (keyEvent->code) {
                case sf::Keyboard::Key::Left:
                    tablero.mover(-1, 0, matrix);
                    continue;
                case sf::Keyboard::Key::Right:
                    tablero.mover(1, 0, matrix);
                    continue;
                case sf::Keyboard::Key::Down:
                    tablero.caida(matrix);
                    continue;
                case sf::Keyboard::Key::Up:
                    tablero.rotar(matrix);
                    continue;
                default: continue;
                }
            }
        }


        
        // Dibujado
        window.clear(BACKGROUND);


        sf::RectangleShape cell({ CELL_SIZE - 1.0f, CELL_SIZE - 1.0f });
        cell.setOutlineThickness(1.0f);
        cell.setOutlineColor({ 50, 50, 50 });

        // Dibujar matriz
        for (unsigned row = 0; row < ROWS; ++row) {
            for (unsigned col = 0; col < COLS; ++col) {
                cell.setPosition({ col * CELL_SIZE * 1.0f, row * CELL_SIZE * 1.0f });
                cell.setFillColor(matrix[row][col] ? FILLED : BACKGROUND);
                window.draw(cell);
            }
        }

        // Pieza actual
        cell.setFillColor(CURRENT_PIECE);
        for (const auto& block : tablero.obtener_bloques()) {
            if (block.y >= 0 && block.x >= 0 && block.x < COLS) {
                cell.setPosition({ block.x * CELL_SIZE * 1.0f, block.y * CELL_SIZE * 1.0f });
                window.draw(cell);
            }
        }

       


            if (timer > FALL_DELAY) {
                timer = 0;
                
                    if (!tablero.caida(matrix))
                    {
                            tablero.actualizar_matriz(matrix);
                            tablero.reset(SHAPES[std::rand() % SHAPES.size()]);

                            if (tablero.pieza_valida(matrix)) 
                            {
                                window.close();
                            }
                        
                    }
            }
        window.display();
    }

    return 0;
}