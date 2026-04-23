#include "Arena.h"

Arena::Arena(Robot* e, Robot* p){
    player = p;
    enemy = e;
    turnCounter = 0;
}

void Arena::start(){
    while(!isGameOver()){
        turnCounter++;

        playerTurn();
        if (isGameOver()) break;

        enemyTurn();
    }

    if (player -> getHp() <= 0)
        std::cout << enemy->getName() << " defeats " << player->getName() << "! WOW! " << enemy->getName() << " won!\n";
    else
        std::cout << player->getName() << " defeats " << enemy->getName() << "! WOW! " << player->getName() << " won!\n";
}

int getInterval(Robot* r){
    return std::max(2, 6 - r->getSpeed() / 10);
}

void Arena::playerTurn(){

    int option;
    // bool valid = false;
    
    // while (!valid){
        std::cout << "YOUR TURN!!!\n";
        std::cout << "1. Basic attack ( deals " << player->getDamage() << " damage and costs 10 energy)\n";
        if (player->getWeapon() != nullptr){
            Weapon* w = player->getWeapon();

            std::cout << "2. Use Weapon (" << w->getName() << " deals " << w->getDamage() << " damage and costs " << w->getEnergyCost() << " energy)\n";
        } else {
            std::cout << "2. Use Wapon (No weapon equipped!)\n";
        }

        std::cout << "3. Special Ability ( ";
        if (player->getType() == "Tank")
            std::cout << "reduces damage by 50% and costs ";
        if (player->getType() == "Assasin")
            std::cout << "get a double turn and costs ";
        if (player->getType() == "Sniper")
            std::cout << "deals double damage for your next attack and costs ";
        std::cout << "40 energy)\n";
        std::cout << "4. Skip round (+15 energy)\n";
        std::cout << "5. Forfeit\n"; 

        std::cout << std::endl << "Your choice: ";
        std::cin >> option;
    // }

    // valid = true;
    
    switch(option){
        case 1:
            player->attack(*enemy);
            std::cout << "Your current energy: " << player->getEenergy();
            break;
        case 2:
            if (player->getWeapon() != nullptr)
                player->getWeapon()->use(*player, *enemy);
            else{
                std::cout << "No weapon equipped!\n";
                // valid = false;
            }
            std::cout << "Your current energy: " << player->getEenergy();
            break;
        case 3:
            player->useSpecialAbility();
            std::cout << "Your current energy: " << player->getEenergy();
            break;
        case 4:
            std::cout << player->getName() << " skips a turn\n";
            player->recoverEnergy(15);
            std::cout << "Your current energy: " << player->getEenergy();
            break;
        case 5:
            std::cout << "Oh no! You lost!\n";
            player->takeDamage(9999);
            break;
        default:
            std::cout << "Invalid Option\n";
            // valid = false;
            break;   
    }
}

void Arena::enemyTurn(){
    int choice = rand() % 4;
    switch (choice){
        case 0:
            enemy->attack(*player);
            break;
        case 1:
            enemy->useSpecialAbility();
            break;
        case 2:
            enemy->getWeapon()->use(*enemy, *player);
            break;
        case 3:
            std::cout << enemy->getName() << " skips a turn\n";
            enemy->recoverEnergy(15);
            break;
    }
}

bool Arena::isGameOver(){
    return player->getHp() <= 0 || enemy->getHp() <= 0;
}