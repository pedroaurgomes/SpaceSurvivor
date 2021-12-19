#include "../includes/Game.hpp"

Game *game = nullptr;

int main (int argc, char *argv[]) {

    const int FPS = 60;
    const int frameDelay = 1000/FPS; // the time a frame is meant to take

    Uint32 frameStart;
    int frameTime;
    
    game = new Game();

    game->init("Space Survivor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 356,600, false);

    // Game loop
    while (game->running()) {

        frameStart = SDL_GetTicks();

        game->handleEvents();

        if(!(game->isOver))
        {
            game->update();
            game->render();
        }
        else 
        {
            game->gameOver();
            
        }

        frameTime = SDL_GetTicks() - frameStart;

        // Adjusting every frame to have the same amount of time(= frameDelay)
        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);

        }
    }

   game->clean();

}