CC = gcc
FLAGS = -Wall -Wextra -O2
TARGET = bin/main
SRC = src/main.c src/input.c src/game.c src/renderer.c src/utils.c src/player.c src/texturemanager.c src/chunk.c
LIBS = `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf -lm

all:
	$(CC) $(FLAGS) -o $(TARGET) $(SRC) $(LIBS)
	./$(TARGET)

comp:
	$(CC) $(FLAGS) -o $(TARGET) $(SRC) $(LIBS)

run:
	./$(TARGET)

test:
	$(CC) $(FLAGS) -o bin/test src/texturemanager.c src/test.c $(LIBS)
	./bin/test

profmem:
	valgrind --tool=massif --massif-out-file=profile.out ./$(TARGET)
	ms_print profile.out

profall:
	valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all --log-file="valgrind.txt" ./$(TARGET)

prof:
	valgrind --log-file="valgrind.txt" ./$(TARGET)

install:
	sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev libsdl2-net-dev
