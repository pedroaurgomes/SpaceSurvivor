#include "../includes/GameObject.hpp"
#include "../includes/TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y, int h, int w) 
{

    objTexture = TextureManager::LoadTexture(textureSheet);

    // Initial positions
    xpos = x;
    ypos = y;

    // Texture dimensions
    height = h;
    width = w;
}

GameObject::~GameObject()
{
    
}

void GameObject::setText(const char* textureSheet)
{
    objTexture = TextureManager::LoadTexture(textureSheet);
}

void GameObject::Update()
{
    //xpos++;
    //ypos++;

    srcRect.h = height;
    srcRect.w = width;
    srcRect.x = 0;
    srcRect.y = 0;
    //srcRect = NULL;


    destRect.x = xpos;
    destRect.y = ypos;
    //destRect.w = srcRect.w * 2;
    //destRect.h = srcRect.h * 2;
    destRect.w = srcRect.w / 2; // scaling by half
    destRect.h = srcRect.h / 2; // scaling by half

    this->move();
}

void GameObject::Render()
{
    SDL_RenderCopy(Game::renderer,objTexture,&srcRect,&destRect);

}

int GameObject::getYPos() 
{
    return this->ypos;
}

int GameObject::getXPos()
{
    return this->xpos;
}

int GameObject::getHeight()
{
    return this->height;
}

void GameObject::setYPos(int y)
{
    this->ypos = y;
}

void GameObject::setXPos(int x)
{
    this->xpos = x;
}

void GameObject::setHeight(int h)
{
    this->height = h;
}