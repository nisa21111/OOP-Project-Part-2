#include "Arena.h"

Arena::Arena(Robot* p, Robot* e){
    player = p;
    enemy = e;
    playerCounter = 0;
    enemyCounter = 0;
}

void Arena::start(){
    while(!isGameOver()){
        playerCounter++;

        playerTurn();
        if (playerCounter >= getInterval(player)){
            std::cout << "Speed bonus!!!\n";
            playerCounter = 0;
            playerTurn();
        }

        if (isGameOver()) break;

        enemyCounter++;
        enemyTurn();
        if (enemyCounter >= getInterval(enemy)){
            std::cout << "Enemy speed bonus! They get an extra round!\n";
            enemyCounter = 0;
            enemyTurn();
        }
    }

    if (player -> getHp() <= 0)
        std::cout << enemy->getName() << " defeats " << player->getName() << "! WOW! " << enemy->getName() << " won!\n";
    else
        std::cout << player->getName() << " defeats " << enemy->getName() << "! WOW! " << player->getName() << " won!\n";
}

int Arena::getInterval(Robot* r){
    return std::max(2, 6 - r->getSpeed() / 10);
}

void Arena::playerTurn(){

    int option;
    bool valid = false;
    
    while (!valid){
        valid = true;
        std::cout << "\nYOUR TURN!!!\n";
        std::cout << "Your current energy: " << player->getEenergy() << "\n";
        std::cout << "Your current HP: " << player->getHp() << "\n";
        std::cout << "Enemy HP: " << enemy->getHp() << "\n\n";
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
        std::cout << "40 energy !DOES NOT FINISH YOUR ROUND!)\n";
        std::cout << "4. Skip round (+15 energy)\n";
        std::cout << "5. Forfeit\n"; 

        std::cout << "\nYour choice: ";
        std::cin >> option;
        std::cout << "___________________________" << "\n";

        switch(option){
            case 1:
                player->attack(*enemy);
                break;
            case 2:
                if (player->getWeapon() != nullptr)
                    player->getWeapon()->use(*player, *enemy);
                else{
                    std::cout << "No weapon equipped!\n";
                    valid = false;
                }
                break;
            case 3:
                if(player->hasSpecialActive() == false){
                    player->useSpecialAbility();
                    playerTurn();
                }
                break;
            case 4:
                std::cout << player->getName() << " skips a turn\n";
                player->recoverEnergy(15);
                break;
            case 5:
                player->takeDamage(9999);
                break;
            default:
                valid = false;
                break;   
        }
    }

    if (player->getType() == "Assasin" && player->hasSpecialActive() == true){
        std::cout << "\nEXTRA TURN !!!\n";
        player->resetSpecialAbility();
        playerTurn();
    }

}

void Arena::enemyTurn(){
    bool enValid = false;
    int choice = rand() % 4;
    while (!enValid){
        enValid = true;
        switch (choice){
            case 0:
                if (enemy->getEenergy() >= 10)
                    enemy->attack(*player);
                else {
                    enValid = false;
                    choice +=2;
                }
                break;
            case 1:
                if(enemy->hasSpecialActive() == true){
                    choice = rand() % 4;
                    enValid = false;
                }
                else {
                    if (enemy->getEenergy() >= 40){
                        enemy->useSpecialAbility();
                        enemyTurn();
                    }
                    else{
                        enValid = false;
                        choice +=2;
                    }
                }
                break;
            case 2:
                if (enemy->getEenergy() >= enemy->getWeapon()->getEnergyCost()){
                    if (enemy->getWeapon()->getWepType() == "RocketLauncher")
                        if (enemy->getWeapon()->isUsed() == true)
                        {
                            enValid = false;
                            choice = rand() % 4;
                            break;
                        }
                    enemy->getWeapon()->use(*enemy, *player);
                }
                else{
                    enValid = false;
                    choice -=1;
                }
                break;
            case 3:
                std::cout << enemy->getName() << " skips a turn\n";
                enemy->recoverEnergy(15);
                break;
        }
    }
    if (enemy->getType() == "Assasin" && enemy->hasSpecialActive() == true){
        std::cout << "\nEnemy gets an extra turn!\n";
        enemy->resetSpecialAbility();
        enemyTurn();
    }
}

bool Arena::isGameOver(){
    return player->getHp() <= 0 || enemy->getHp() <= 0;
}