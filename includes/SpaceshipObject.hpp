#pragma once

#include "Game.hpp"
#include "GameObject.hpp"
#include "Score.hpp"

class SpaceshipObject : public GameObject {


public:

    bool intangible;

    // Constructor and destructor
    SpaceshipObject(const char* textureSheet, int x, int y, int h, int w);
    ~SpaceshipObject();


    void move();

    void setStartTime(int st);
    void setCooldown(int cd);


private:
    int startTime;
    int cooldown;
};