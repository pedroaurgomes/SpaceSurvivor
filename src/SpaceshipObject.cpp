
#include "../includes/SpaceshipObject.hpp"

SpaceshipObject::SpaceshipObject(const char* textureSheet, int x, int y, int h, int w) 
: GameObject::GameObject(textureSheet,x,y,h,w)
{

}

void SpaceshipObject::move() 
{    
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
            case SDLK_BACKSPACE: 
            // lembrar de estabelecer um tempo max para a tecla ficar pressionada ( o jogador não pode pular o tempo inteiro)
            // como identificar um asteroide enquanto o jogador estiver pulando??



            default:
                break;

        }

    }

}