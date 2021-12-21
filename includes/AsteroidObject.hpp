#pragma once
#include "Game.hpp"
#include "GameObject.hpp"
#include <algorithm>

class AsteroidObject : public GameObject {


public:

    // Constructor and destructor
    AsteroidObject(const char* textureSheet, int x, int y, int h, int w);
    ~AsteroidObject();

    void move();

private:
    int speed;

};