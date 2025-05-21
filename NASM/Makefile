CXX = g++
NASM = nasm

CXXFLAGS = -c -Wall -Wextra
NASMFLAGS = -f elf64

TARGET = test

CPP_SRCS = test.cpp
ASM_SRCS = movement.asm collision.asm

CPP_OBJS = $(CPP_SRCS:.cpp=.o)
ASM_OBJS = $(ASM_SRCS:.asm=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(CPP_OBJS) $(ASM_OBJS)
	$(CXX) $^ -o $@ -no-pie

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

clean:
	rm -f $(CPP_OBJS) $(ASM_OBJS) $(TARGET)

run: all
	./$(TARGET)
