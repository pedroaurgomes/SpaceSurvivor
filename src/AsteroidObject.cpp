#include "../includes/AsteroidObject.hpp"

AsteroidObject::AsteroidObject(const char* textureSheet, int x, int y, int h, int w) 
: GameObject::GameObject(textureSheet,x,y,h,w)
{
    speed = (rand()%3) + 1;
}

AsteroidObject::~AsteroidObject()
{

}

void AsteroidObject::move() 
{   

    this->ypos += speed;

    /*
    // Quando o asteroide sair da tela, destrua-o
    if(ypos >= 600)    
    {
    
        AsteroidSpawner::asteroids.erase(std::remove(AsteroidSpawner::asteroids.begin(), 
        AsteroidSpawner::asteroids.end(), this), AsteroidSpawner::asteroids.end());
        

        this->~AsteroidObject();
        // decrementar número de asteroides na tela
    }
    */
}   

int AsteroidObject::getYPos() 
{
    return this->ypos;
}

int AsteroidObject::getXPos()
{
    return this->xpos;
}