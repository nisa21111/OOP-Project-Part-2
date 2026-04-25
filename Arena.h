#ifndef ARENA_H
#define ARENA_H

#include "Robot.h"
#include "Weapon.h"
#include <iostream>

class Arena {
private:
    Robot* player;
    Robot* enemy;

    int playerCounter;
    int enemyCounter;

public:
    Arena(Robot* p, Robot* e);

    void start();
    void saveGame();

private:
    int getInterval(Robot* r);
    void playerTurn();
    void enemyTurn();
    bool isGameOver();

};

#endif