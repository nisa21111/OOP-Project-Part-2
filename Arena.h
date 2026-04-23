#ifndef ARENA_H
#define ARENA_H

#include "Robot.h"
#include "Weapon.h"
#include <iostream>

class Arena {
private:
    Robot* player;
    Robot* enemy;

    int turnCounter;

public:
    Arena(Robot* p, Robot* e);

    void start();

private:
    void playerTurn();
    void enemyTurn();
    bool isGameOver();

};

#endif