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

//save // edge cases //weapon extend//make robot based on class(change string == la extra turn si spec ability in arena)??meniul principal si enemy robot select (in main)
