# 🎮 Tetrix SFML - Proyecto de Juego de Tetris

<div align="center">
  <img src="https://media.giphy.com/media/3o7TKUM3IgJBX2as9O/giphy.gif" width="200"/>
</div>

---

## 📜 Descripción del Proyecto
**Tetrix SFML** es una implementación básica del clásico juego Tetris desarrollada en C++ utilizando la biblioteca SFML (Simple and Fast Multimedia Library). Este proyecto demuestra los fundamentos de la programación de juegos, incluyendo renderizado gráfico, manejo de eventos y lógica de juego.

---

## 🛠️ Tecnologías Utilizadas
- **C++17** - Lenguaje de programación principal
- **SFML 3.0+** - Biblioteca multimedia para gráficos, ventanas y eventos

---

## 📁 Estructura del Código
```cpp
// main.cpp - Contiene la lógica principal del juego
#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

// Definiciones básicas
const unsigned char cols = 10;    // Columnas del tablero
const unsigned char rows = 20;    // Filas del tablero
const unsigned int celdas = 20;   // Tamaño de cada celda en píxeles

// Lógica principal del juego
int main() {
    // Inicialización de ventana SFML
    // Manejo de eventos (clic del mouse)
    // Renderizado del tablero
    // Lógica básica del juego
}
```

---

## 🎯 Características Actuales
- ✅ Tablero de juego 10x20 celdas
- ✅ Renderizado básico de celdas
- ✅ Interacción con el mouse para activar/desactivar celdas
- ✅ Sistema de temporización básico

---

## 🚀 Instalación y Ejecución
### Requisitos previos:
- Compilador C++ compatible con C++17
- SFML 3.0 instalado

### Compilación manual:
```bash
g++ -std=c++17 Teatrix_sfml.cpp -o tetrix -lsfml-graphics -lsfml-window -lsfml-system
```

### Ejecución:
```bash
./tetrix
```

---

## 🕹️ Controles
- **Clic izquierdo**: Alternar estado de la celda (activar/desactivar)
- **Cerrar ventana**: Salir del juego

---

## 📌 Próximas Mejoras (Roadmap)
- [ ] Implementar piezas de Tetris reales
- [ ] Añadir controles de teclado
- [ ] Implementar rotación de piezas
- [ ] Añadir sistema de puntuación
- [ ] Implementar colisión y líneas completas
- [ ] Añadir diferentes colores para cada pieza


---

<div align="center">
  <img src="https://media.giphy.com/media/26tn33aiTi1jkl6H6/giphy.gif" width="300"/>
  <p>¡Diviértete programando y jugando!</p>
</div>

¿Necesitas que agregue o modifique alguna sección específica del README? Estoy aquí para ayudarte a personalizarlo según tus necesidades.