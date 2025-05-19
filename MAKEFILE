# Makefile para Tetrix con SFML
# Autor: 
# Versión: 1.0

# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Nombre del ejecutable
TARGET = tetrix

# Archivos fuente
SRC = Teatrix_sfml.cpp

# Regla principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

# Limpiar archivos generados
clean:
	rm -f $(TARGET)

# Instalar dependencias (SFML en Ubuntu/Debian)
install-deps:
	sudo apt-get install libsfml-dev

# Ejecutar el juego
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run install-deps