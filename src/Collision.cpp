#include "../includes/Collision.hpp"


void Collision::checkCollision(SpaceshipObject* player, std::vector<AsteroidObject*> asteroids, bool* isOver)
{
    for (auto ast : AsteroidSpawner::asteroids)
    {    
        if(((ast->getYPos() + ast->getHeight()/2) >= player->getYPos()) // Lembrando que os sprites estão escalonados pela metade
        && (ast->getXPos() == player->getXPos()))
        {
            if(!player->intangible) 
            {
                // GameOver
                (*isOver) = true;

                // Voltando a nave para a posição inicial
                player->setXPos(118);
                
                // Destruindo asteroides
                for(auto ast : AsteroidSpawner::asteroids)
                {
                    ast->~AsteroidObject();
                }
                AsteroidSpawner::asteroids.clear();
                AsteroidSpawner::nAst = 0;

                // Resetando timers
                player->setCooldown(0);
                player->setStartTime(-7);    
            }
            
            else 
            {
                // Pontua
                Score::score++;
            }
        }
    }
}