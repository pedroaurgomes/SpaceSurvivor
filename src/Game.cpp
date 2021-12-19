#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
#include "../includes/GameObject.hpp"
#include "../includes/SpaceshipObject.hpp"
#include "../includes/AsteroidObject.hpp"
#include "../includes/AsteroidSpawner.hpp"
#include "../includes/Collision.hpp"


SpaceshipObject* player; // spaceship
bool Game::isOver = false;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;



Game::Game() 
{

}

Game::~Game()
{

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{

    int flags = 0;
    isOver = false;

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

    // Setting the background
    BackTexture = TextureManager::LoadTexture("../assets/background.png");
    backDestRect.w = 356;
    backDestRect.h = 600;

    GameOverTexture = TextureManager::LoadTexture("../assets/gameover.png");
    gameOverRect.w = 356;
    gameOverRect.h = 600;

    player = new SpaceshipObject("../assets/spaceship.png",118,500,206,237);

}

void Game::handleEvents()
{
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
    //Clock::getCurrentTime(); --> colocar tempo na tela
    //std::cout << SDL_GetTicks()/1000 << std::endl;

    player->Update();

    AsteroidSpawner::spawning();
    AsteroidSpawner::destroyAsteroids();

    for(auto ast : AsteroidSpawner::asteroids)
    {
        //std::cout << ast->getXPos() << " "<< ast->getYPos() << std::endl;
        ast->Update();
    }

    // Checking collision
    Collision::checkCollision(player, AsteroidSpawner::asteroids, &isOver);

    // Incrementar o score a cada segundo usando SDL_GetTicks()/1000
}

void Game::render()
{
    SDL_RenderClear(renderer);

    // Rendering the background
    SDL_RenderCopy(renderer,BackTexture,NULL,&backDestRect);

    player->Render();

    // Rendering the asteroids
    for(auto ast : AsteroidSpawner::asteroids)
    {
        //std::cout << ast->getXPos() << " "<< ast->getYPos() << std::endl;
        ast->Render();
    }

    SDL_RenderPresent(renderer);
}

void Game::gameOver() 
{
    SDL_RenderClear(renderer);

    // Renderiza a tela de game over
    SDL_RenderCopy(renderer,GameOverTexture,NULL,&gameOverRect);

    // renderizar o score 

    // Game restart
    if((Game::event.type == SDL_KEYDOWN) && (Game::event.key.keysym.sym == SDLK_r))
    {
        // Reset score (fazer)
        // reset timer (fazer)

        isOver = false;
    }
 
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}
