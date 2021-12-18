#pragma once
#include "Game.hpp"
#include "GameObject.hpp"
#include "AsteroidObject.hpp"
#include <vector>

class AsteroidSpawner {

public:
		static int nAst; // número de asteroides na cena
		static std::vector<AsteroidObject*> asteroids;

		static void spawning();
        static void initAsteroids();
		static void destroyAsteroids();
		
private:
		static void AsteroidCreate();
		static bool checkAstPos(AsteroidObject* ast);

};