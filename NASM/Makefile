CXX = g++
NASM = nasm

CXXFLAGS = -m32 -c -Wall -Wextra -g
NASMFLAGS = -f elf32 -g

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

TARGET = $(BIN_DIR)/test

CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
ASM_SRCS = $(wildcard $(SRC_DIR)/*.asm)

CPP_OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(CPP_SRCS))
ASM_OBJS = $(patsubst $(SRC_DIR)/%.asm,$(OBJ_DIR)/%.o,$(ASM_SRCS))

OBJS = $(CPP_OBJS) $(ASM_OBJS)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) -m32 $^ -o $@

# Regla para archivos .cpp
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Regla para archivos .asm
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.asm
	@mkdir -p $(OBJ_DIR)
	$(NASM) $(NASMFLAGS) -o $@ $<

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

run: all
	./$(TARGET)
