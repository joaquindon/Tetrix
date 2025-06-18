# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2
LDFLAGS = -lsfml-system -lsfml-window -lsfml-graphics
TARGET = game

SRC = main.cpp Board.cpp Parts.cpp
OBJ = $(SRC:.cpp=.o) logic.o

ASM = nasm
ASMFLAGS = -f elf64
ASM_SRC = logic.asm
ASM_OBJ = logic.o

# Regla principal
all: $(TARGET)

# Linkeo final
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

# Compilación de cada .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilación de .asm a .o
%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Ejecutar
run: $(TARGET)
	./$(TARGET)

# Declaración de phony targets
.PHONY: all clean run
