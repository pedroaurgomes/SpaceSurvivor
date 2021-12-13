#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
#include "../includes/GameObject.hpp"

GameObject* player; // spaceship

SDL_Renderer* Game::renderer = nullptr;

Game::Game() 
{

}

Game::~Game()
{

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    int flags = 0;

    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL Subsystems Initialized!..." << std::endl;

        window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);
        if(window)
            std::cout << "Window created!" << std::endl;

        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
            std::cout << "Renderer created!" << std::endl;
        }   
        isRunning = true;

    }
    else {
        isRunning = false;
    }

    player = new GameObject("../assets/spaceship.png",118,500,206,237);

}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
    
        default:
            break;
    }
}

void Game::update() 
{
    /*
    cnt++;

    // Escala 2x menor (tamanho original: 206x237)
    destRect.h = 103.f;
    destRect.w = 117.5f;

    destRect.x = cnt;

    std::cout << cnt << std::endl;
    */

    player->Update();
}

void Game::render()
{
    SDL_RenderClear(renderer);

    // adding objects to render
    //SDL_RenderCopy(renderer, playerTex,NULL,&destRect); 
    player->Render();

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
