#ifndef Game_hpp
#define Game_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <thread>

class Game { 

public:
    // Constructor and Deconstructor
    Game();
    ~Game();

    // => Functions
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void handleEvents();
    void update();
    void render();
    void clean();

    bool running() {return this->isRunning;}

    void gameOver();

    static int getCurrentTime();

    // => Variables
    static SDL_Renderer* renderer;
    static SDL_Event event;

    static bool isOver;
    static int startTime;


private:

    // => Variables 
    int cnt = 0; //counter
    bool isRunning;
    SDL_Window* window;
    SDL_Texture* BackTexture;
    SDL_Texture* GameOverTexture;
    SDL_Rect backDestRect;
    SDL_Rect gameOverRect;
    SDL_Rect textRect;
    static int prevTime; // guarda o tempo anterior até completar 1 segundo (incrementar score)

    static std::thread tdTimeScore;
    static std::thread tdCollisionScore;

    // => Functions
    static void scoreByTime();
};


#endif