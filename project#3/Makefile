# Makefile example
CC = g++
TARGET = tetris
SOURCES = Tetris.cpp \
	Pane.cpp \
	InfoPane.cpp \
	HelpPane.cpp \
	main.cpp \
	Block.cpp \
	L_Block.cpp \
	Z_Block.cpp \
	O_Block.cpp \
	T_Block.cpp \
	I_Block.cpp \
	J_Block.cpp \
	S_Block.cpp \
	NextPane.cpp
LDFLAGS = -lncurses

all:
	$(CC) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -rf *.o $(TARGET)
