#pragma once
#include <SFML/System/Vector2.hpp>
#include <array>
#include <vector>
#include <optional>
#include <algorithm>  // Para std::any_of

using Position = sf::Vector2i;  // Usamos el tipo vector de SFML

class Tablero {
private:
    const float FALL_DELAY = 0.5f;
    sf::Clock clock;
    float timer = 0;
    // Tipos fuertemente tipados para mejor seguridad
    enum class Rotacion { _0, _90, _180, _270 };

    // Constantes de diseño
    static constexpr std::array FORMAS_BASE = 
    {
        std::array{Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1}},   // I
        std::array{Position{0,1}, Position{1,1}, Position{2,1}, Position{2,0}},   // J
        std::array{Position{0,1}, Position{1,1}, Position{2,1}, Position{2,2}},   // L
        std::array{Position{0,0}, Position{1,0}, Position{0,1}, Position{1,1}},   // O
        std::array{Position{1,0}, Position{2,0}, Position{0,1}, Position{1,1}},   // S
        std::array{Position{1,0}, Position{0,1}, Position{1,1}, Position{2,1}},   // T
        std::array{Position{0,0}, Position{1,0}, Position{1,1}, Position{2,1}}    // Z
    };
    // Miembros
    
    Position posicion{ 4, 0 };  // Inicialización uniforme
    Rotacion rotacion{ Rotacion::_0 };
    std::vector<Position> bloques;

public:
    enum class FormaPieza { I, J, L, O, S, T, Z };
    FormaPieza forma;

    explicit Tablero(FormaPieza forma = FormaPieza::I) noexcept
        : forma{ forma } {
        inicializar_forma();
    }

    void reset(FormaPieza nueva_forma) noexcept {
        forma = nueva_forma;
        posicion = { 4, 0 };
        rotacion = Rotacion::_0;
        inicializar_forma();
    }

    bool caida(std::vector<std::vector<unsigned char>>& matriz) noexcept 
    {            


        while (!colision(matriz)) 
        { 
            posicion.y += 1;
            
            if (colision(matriz))
            {
                posicion.y -= 1;
                return false;
            }
        }
        
        return true;
    }

    void actualizar_matriz(std::vector<std::vector<unsigned char>>& matriz) const noexcept {
        for (const auto& bloque : bloques_transformados()) {
            if (auto [x, y] = bloque; y >= 0 && x >= 0 &&
                y < static_cast<int>(matriz.size()) &&
                x < static_cast<int>(matriz[0].size())) {
                matriz[y][x] = 1;
            }
        }
    }

    void mover(int dx, int dy, const std::vector<std::vector<unsigned char>>& matriz) noexcept {
        posicion.x += dx;
        posicion.y += dy;
        if (colision(matriz)) {
            posicion.x -= dx;
            posicion.y -= dy;
        }
    }

    void rotar(const std::vector<std::vector<unsigned char>>& matriz) noexcept {
        const auto rotacion_original = rotacion;
        rotacion = static_cast<Rotacion>((static_cast<int>(rotacion) + 1) % 4);

        aplicar_rotacion();

        if (!colision(matriz)) {
            rotacion = rotacion_original;
            revertir_rotacion();
        }
    }

    [[nodiscard]] bool pieza_valida(const std::vector<std::vector<unsigned char>>& matriz) const noexcept {
        return colision(matriz);
    }

    [[nodiscard]] auto obtener_bloques() const noexcept -> const std::vector<Position>& {
        return bloques_transformados();
    }

private:
    void inicializar_forma() noexcept {
        bloques = {};
        const auto& forma_base = FORMAS_BASE[static_cast<size_t>(forma)];
        bloques.insert(bloques.end(), forma_base.begin(), forma_base.end());
    }

bool colision(const std::vector<std::vector<unsigned char>>& matriz) const noexcept {
    for (const auto& bloque : bloques_transformados()) {
        const int x = bloque.x;
        const int y = bloque.y;

        // Verificar límites del tablero y colisión con bloques ya existentes
        if (x < 0 || x >= matriz[0].size() ||   // Fuera por izquierda/derecha
            y >= matriz.size() ||               // Fuera por abajo
            (y >= 0 && matriz[y][x])) {        // Dentro del tablero y hay un bloque
            return true;
        }
    }
    return false; // No hay colisión
}

    [[nodiscard]] std::vector<Position> bloques_transformados() const noexcept {
        std::vector<Position> resultado;
        resultado.reserve(bloques.size());

        for (const auto& bloque : bloques) {
            auto [x, y] = bloque;

            // Aplicar rotación
            for (int i = 0; i < static_cast<int>(rotacion); ++i) {
                std::tie(x, y) = std::pair{ -y, x };  // Rotación 90°
            }

            resultado.emplace_back(posicion.x + x, posicion.y + y);
        }
        return resultado;
    }

    void aplicar_rotacion() noexcept {
        for (auto& bloque : bloques) {
            auto [x, y] = bloque;
            for (int i = 0; i < static_cast<int>(rotacion); ++i) {
                std::tie(x, y) = std::pair{ -y, x };
            }
            bloque = { x, y };
        }
    }

    void revertir_rotacion() noexcept {
        for (auto& bloque : bloques) {
            auto [x, y] = bloque;
            for (int i = 0; i < 3; ++i) {  // Rotación inversa (270°)
                std::tie(x, y) = std::pair{ -y, x };
            }
            bloque = { x, y };
        }
    }
};