#pragma once
#include "AsteroidSpawner.hpp"
#include "SpaceshipObject.hpp"
#include "Score.hpp"

class Collision {

public:
    static void checkCollision(SpaceshipObject* player, std::vector<AsteroidObject*> asteroids, bool* isOver);
    
private:

};