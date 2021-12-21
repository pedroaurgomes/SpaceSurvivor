CC=g++
SOURCE=Game.cpp GameObject.cpp TextureManager.cpp SpaceshipObject.cpp AsteroidObject.cpp AsteroidSpawner.cpp Collision.cpp Score.cpp
PROG=main.cpp
TARGET= main

all:
	@$(CC) -o $(TARGET) $(SOURCE) $(PROG) -pthread -lSDL2 -lSDL2_image -lSDL2_ttf

run:
	@./$(TARGET)


