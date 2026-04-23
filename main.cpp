#include <iostream>
#include "Arena.h"
#include "Tank.h"
#include "Assasin.h"
#include "Sniper.h"
#include "Weapon.h"

int main(){
    Robot* player = new Tank("Titan");
    Robot* enemy = new Assasin("Flash");

    player->equipWeapon(new Crossbow());
    enemy->equipWeapon(new LaserGun());

    Arena arena (player, enemy);

    arena.start();

    delete player;
    delete enemy;

    return 0;
}

// spec ability assasin//some msg//validator//show hp7
