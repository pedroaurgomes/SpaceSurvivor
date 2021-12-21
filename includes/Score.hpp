#pragma once
#include <iostream>
#include <mutex>
#include <thread>

class Score {

public:

    static int score;
    static std::mutex mtxScore;
    static void addScore();

private:

};