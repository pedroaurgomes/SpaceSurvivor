#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

class Game { 

public:
    // => Variables


    // => Functions
    // Constructor and Deconstructor
    Game();
    ~Game();

    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {return this->isRunning;}

    void gameOver();

    static SDL_Renderer* renderer;
    static SDL_Event event;
    static bool isOver;

private:

    // => Variables 
    int cnt = 0; //counter
    bool isRunning;
    SDL_Window* window;
    SDL_Texture* BackTexture;
    SDL_Texture* GameOverTexture;
    SDL_Rect backDestRect;
    SDL_Rect gameOverRect;



};


#endif