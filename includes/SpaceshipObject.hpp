#pragma once

#include "Game.hpp"
#include "GameObject.hpp"

class SpaceshipObject : public GameObject {


public:
    // Constructor and destructor
    SpaceshipObject(const char* textureSheet, int x, int y, int h, int w);
    ~SpaceshipObject();


    void move();


private:


};