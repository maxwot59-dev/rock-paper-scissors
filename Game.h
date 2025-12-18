#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <string>

class Game {
private:
    Player player1;
    Player player2;
    int roundsToWin;

    int determineWinner(int choice1, int choice2);
    void printResult(int choice1, int choice2, int winner);

public:
    Game(const std::string& name1, const std::string& name2, int rounds = 3);
    void start();
};

#endif