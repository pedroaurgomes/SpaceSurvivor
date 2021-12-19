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
}   

