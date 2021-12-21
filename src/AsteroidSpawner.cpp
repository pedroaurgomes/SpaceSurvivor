#include "../includes/AsteroidSpawner.hpp"

int AsteroidSpawner::nAst = 0; // número de asteroides na cena
std::vector<AsteroidObject*> AsteroidSpawner::asteroids;

void AsteroidSpawner::spawning()
{
	// Se houver menos do que 3 asteroides na tela, spawnamos um asteroide
	if(AsteroidSpawner::nAst < 3) 
	{
		AsteroidCreate();
		AsteroidSpawner::nAst++;
	}
}

void AsteroidSpawner::AsteroidCreate() 
{
	AsteroidObject* ast;
	int xpos;
	// Escolher uma lane aleatoriamente para spawnar o asteroide
	// Lane 1: (x=0,y=0)
	// Lane 2: (x=118,y=0)
	// Lane 3: (x=236,y=0)
	xpos = (rand() % 3)*118; //  x = 0 || x = 118 || x = 236 

	// (textureSheet,x,y,h,w) 
	// y é sempre = 0
	ast = new AsteroidObject("../assets/newAsteroidHorizontal.png",xpos,-206,206,237);
    
    AsteroidSpawner::asteroids.push_back(ast);
}

void AsteroidSpawner::destroyAsteroids()
{
	AsteroidSpawner::asteroids.erase(std::remove_if(AsteroidSpawner::asteroids.begin(), 
        AsteroidSpawner::asteroids.end(), AsteroidSpawner::checkAstPos), AsteroidSpawner::asteroids.end());
}

bool AsteroidSpawner::checkAstPos(AsteroidObject* ast) 
{
	if(ast->getYPos() >= 600) 
	{

		ast->~AsteroidObject();
		AsteroidSpawner::nAst--;
		return true;
	}

	return false;
}