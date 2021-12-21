#include "../includes/Score.hpp"

int Score::score = 0; // obtido através do tempo e de transpassar um asteroide
std::mutex Score::mtxScore;

// Regiao critica
void Score::addScore() 
{
    Score::mtxScore.lock();
    Score::score++;
    Score::mtxScore.unlock();
}