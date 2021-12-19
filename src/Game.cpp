#include "../includes/Game.hpp"
#include "../includes/TextureManager.hpp"
#include "../includes/GameObject.hpp"
#include "../includes/SpaceshipObject.hpp"
#include "../includes/AsteroidObject.hpp"
#include "../includes/AsteroidSpawner.hpp"
#include "../includes/Collision.hpp"
#include "../includes/Score.hpp"


SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
TTF_Font* font = nullptr;
SDL_Color color = {255,255,255,255};
SDL_Surface* textSurface = nullptr;
SDL_Texture* scoreTexture = nullptr; 


SpaceshipObject* player; // spaceship
bool Game::isOver = false;
int Game::startTime = 0;
int Game::prevTime = 0;


Game::Game() 
{

}

Game::~Game()
{

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    startTime = SDL_GetTicks()/1000;
    prevTime = startTime;
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

        // Score text settings
        if(TTF_Init() < 0)
        {
            std::cout << "Error: " << TTF_GetError() << std::endl;  
        }

        font = TTF_OpenFont("../assets/Antonio-Bold.ttf", 40);

        isRunning = true;

    }
    else {
        isRunning = false;
    }

    // Setting the background
    BackTexture = TextureManager::LoadTexture("../assets/background.png");
    backDestRect.w = 356;
    backDestRect.h = 600;

    // Setting gameover screen
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
    player->Update();

    AsteroidSpawner::spawning();
    AsteroidSpawner::destroyAsteroids();

    for(auto ast : AsteroidSpawner::asteroids)
    {
        ast->Update();
    }

    // Checking collision
    Collision::checkCollision(player, AsteroidSpawner::asteroids, &isOver);
    
    // Incrementar o score a cada segundo usando SDL_GetTicks()/1000
    if (getCurrentTime() - prevTime >= 1) 
    {
        Score::score++; 
        prevTime = getCurrentTime();
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);

    // Rendering the background
    SDL_RenderCopy(renderer,BackTexture,NULL,&backDestRect);

    // Rendering the player
    player->Render();

    // Rendering the asteroids
    for(auto ast : AsteroidSpawner::asteroids)
    {
        ast->Render();
    }

    // Setting score text
    std::string text = "SCORE: ";
    const char* scoreString = NULL;

    text += std::to_string(Score::score);
    scoreString = text.c_str();

    textSurface = TTF_RenderText_Solid(font,scoreString,color);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    // Setting score rect
    textRect.x = 5;
    textRect.y = 0;
    SDL_QueryTexture(scoreTexture,NULL,NULL,&textRect.w, &textRect.h);
    SDL_FreeSurface(textSurface);
    textSurface = nullptr;

    // rendering score
    SDL_RenderCopy(renderer, scoreTexture, NULL, &textRect);

    SDL_RenderPresent(renderer);
}

void Game::gameOver() 
{
    SDL_RenderClear(renderer);

    // Renderiza a tela de game over
    SDL_RenderCopy(renderer,GameOverTexture,NULL,&gameOverRect);

    // renderizar o score 
    textRect.x = 100;
    textRect.y = 500;
    SDL_QueryTexture(scoreTexture,NULL,NULL,&textRect.w, &textRect.h);

    SDL_RenderCopy(renderer, scoreTexture, NULL, &textRect);

    // Game restart
    if((Game::event.type == SDL_KEYDOWN) && (Game::event.key.keysym.sym == SDLK_r))
    {
        // reset score
        Score::score = 0;

        // reset timer 
        startTime = SDL_GetTicks()/1000;
        prevTime = getCurrentTime();

        // game over
        isOver = false;
    }
 
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game Cleaned!" << std::endl;
}

int Game::getCurrentTime() 
{
    return SDL_GetTicks()/1000 - startTime;
}