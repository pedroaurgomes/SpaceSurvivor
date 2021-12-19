
#include "../includes/SpaceshipObject.hpp"

SpaceshipObject::SpaceshipObject(const char* textureSheet, int x, int y, int h, int w) 
: GameObject::GameObject(textureSheet,x,y,h,w)
{
    this->intangible = false;
    this->cooldown = 0;
    this->startTime = -7; // evitando o cooldown nos primeiros 7 segundos do jogo
}

void SpaceshipObject::move() 
{    
    if (((SDL_GetTicks()/1000 - this->cooldown) >= 5) && (this->intangible))
    {
        this->intangible = false;
        std::cout << "tangível" << std::endl;
        //trocar 
        this->setText("../assets/spaceship.png");
    }

    if (Game::event.type == SDL_KEYDOWN)
    {       
        switch (Game::event.key.keysym.sym) 
        {
            // moving left
            case SDLK_a:
                // Se a nave já não estiver na lane mais a esquerda
                if (xpos > 0)
                {
                    this->xpos -= 118;
                }

                break;

            //  moving right
            case SDLK_d:
                // Se a nave já não estiver na lane mais a direita
                if (xpos < 236)
                {
                    this->xpos += 118;
                }

                break;

            // Intangibility
            case SDLK_SPACE:

                std::cout << "clicou" << std::endl;
                std::cout <<  SDL_GetTicks()/1000 << std::endl;
                if ((!this->intangible) && (( SDL_GetTicks()/1000 - this->startTime) >= 7))
                {
                    this->intangible = true;
                    std::cout << "intangível" << std::endl;
                    this->startTime = SDL_GetTicks()/1000;
                    this->cooldown = SDL_GetTicks()/1000;
                    
                    //TODO renderizar a nave intangível
                    //this->newRender()
                    this->setText("../assets/spaceship_transparent.png");
                }
                
            default:
                break;

        }

    }

}