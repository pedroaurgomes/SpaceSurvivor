#include "../includes/Collision.hpp"


void Collision::checkCollision(SpaceshipObject* player, std::vector<AsteroidObject*> asteroids)
{
    for (auto ast : AsteroidSpawner::asteroids)
    {    
        if(((ast->getYPos() + ast->getHeight()/2) >= player->getYPos()) // Lembrando que os sprites estão escalonados pela metade
        && (ast->getXPos() == player->getXPos()))
        {
            if(!player->intangible) 
            {
                // GameOver
                std::cout << "colidiu" << std::endl;
            }
            else 
            {
                // Pontua
                std::cout << "pontuou" << std::endl;
            }
        }
    }
}