#pragma once
#include "Game.hpp" 

class GameObject {

public:
    // Constructor and destructor
    GameObject(const char* textureSheet, int x, int y, int h, int w);
    ~GameObject();

    void Update();
    void Render();
    virtual void move() = 0; // pure virtual function
                            // as classes que herdam de GameObject devem implementar essa funcao
    int getYPos();
    int getXPos();
    int getHeight();

    void setYPos(int y);
    void setXPos(int x);
    void setHeight(int h);

    void setText(const char* textureSheet);

    

protected: 
    // positions
    int xpos;
    int ypos;

    // Texture dimensions
    int height;
    int width;

private:
    SDL_Texture* objTexture;
    SDL_Rect srcRect, destRect;
    SDL_Renderer* renderer;

};