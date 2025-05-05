// Teatrix_sfml.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

int main()
{

    const unsigned char cols = 10;
    const unsigned char rows = 20;
    const unsigned int celdas = 20;
    const unsigned char pantalla = 1;
    std::array<Punto, 4> pieza = { {
    {4, 0},
    {4, 1},
    {4, 2},
    {4, 3}
    } };

    float timer = 0.0f;
    float delay = 0.5f;


    sf::RenderWindow window(sf::VideoMode({cols * celdas, rows * celdas}), "Tetrix");
    window.setFramerateLimit(60);

    std::vector<std::vector<unsigned char>> matrix(cols, std::vector<unsigned char>(rows));
    while (window.isOpen())
    {

        while (const std::optional<sf::Event> event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }

            else if (event->is<sf::Event::MouseButtonPressed>())
            {
                const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>();
                if (mouseEvent->button == sf::Mouse::Button::Left)
                {
                    int x = mouseEvent->position.x / celdas / pantalla;
                    int y = mouseEvent->position.y / celdas / pantalla;

                    if (x >= 0 && x < cols && y >= 0 && y < rows)
                        matrix[x][y] = 1 - matrix[x][y];
                }
            }


        }


        window.clear(sf::Color(40, 40, 40));
        
        sf::RectangleShape cuadros(sf::Vector2f(celdas - 1, celdas - 1));

        cuadros.setFillColor(sf::Color(10, 10, 10));

        for (unsigned char i = 0; i < cols; i++)
        {
            for (unsigned char j = 0; j < rows; j++)
            {
                cuadros.setPosition({ static_cast<float>(celdas * i), static_cast<float>(celdas * j) });

                if (matrix[i][j])
                    cuadros.setFillColor(sf::Color(255,0,0));
                else
                    cuadros.setFillColor(sf::Color(10, 10, 10));

                window.draw(cuadros);
            }
        }

        window.display();
    }
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
