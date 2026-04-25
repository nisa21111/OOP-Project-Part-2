#include <iostream>
#include "Arena.h"
#include "Tank.h"
#include "Assasin.h"
#include "Sniper.h"
#include "Weapon.h"


Robot* generateRandomRobot(){
    int r = rand() % 3;
    switch (r){
        case 0:
            return new Tank("Titan");
        case 1:
            return new Assasin("Flash");
        default:
            return new Sniper("Ghost");
    }
}

Weapon* generateRandomWeapon(){
    int r = rand() % 3;
    switch (r){
        case 0:
            return new LaserGun();
        case 1:
            return new Crossbow();
        default:
            return new RocketLauncher();
    }
}

Robot* createRobotFromFile(std::istream& in){
    std::string type;
    in >> type;
    Robot* r = nullptr;
    if (type == "Tank") r = new Tank();
    else if (type == "Assasin") r = new Assasin();
    else if (type == "Sniper") r = new Sniper();
    else{
        std::cout << "Unknown robot type: " << type << "\n";
        return nullptr;
    }

    r->loadFromFile(in);
    return r;
}

Weapon* createWeaponFromFile(std::istream& in){
    std::string type;
    in >> type;

    Weapon* w = nullptr;

    if (type == "LaserGun") w = new LaserGun();
    else if (type == "Crossbow") w = new Crossbow();
    else if (type == "RocketLauncher") w = new RocketLauncher();
    else{
        std::cout << "Unknown Weapon type: " << type << "\n";
        return nullptr;
    }

    w->loadFromFile(in);
    return w;
}

int main(){
    srand(time(0));

    Robot* player = nullptr;
    Weapon* playerWeapon = nullptr;

    bool running = true;


    while (running){
        std::cout << "\nWealcome to Robot Battle Arena\n";
        std::cout << "1. Choose your Robot\n";
        std::cout << "2. Equip a Weapon\n";
        std::cout << "3. Start the Battle\n";
        std::cout << "4. Info\n";
        std::cout << "5. Exit\n";
        std::cout << "6. Load Game\n";

        int choice;
        std::cout << "\nYour choide: ";
        std::cin >> choice;

        switch (choice){
            case 1:{
                std::cout << "Available Robots:\n1. Tank\n2. Assasin\n3. Sniper\n";
                int r;
                std::cin >> r;
                delete player;

                if (r == 1) player = new Tank("Titan");
                else if (r == 2) player = new Assasin("Flash");
                else if (r == 3) player = new Sniper("Ghost");
                else std::cout << "Invalid choice\n";
                break;
            }
            case 2:{
                if(!player){
                    std::cout << "Choose Robot first!\n";
                    break;
                }
                std::cout << "Available Weapons:\n" << "1. Laser Gun\n2. Crossbow\n3. Rocket Launcher\n";
                int w;
                std::cout << "\nYour choice: ";
                std::cin >> w;

                delete playerWeapon;

                if (w == 1) playerWeapon = new LaserGun();
                else if (w == 2) playerWeapon = new Crossbow();
                else if (w == 3) playerWeapon = new RocketLauncher();
                else std::cout << "Invalid choice!\n";

                player->equipWeapon(playerWeapon);
                break;
            }
            case 3:{
                if (!player){
                    std::cout << "Choose Robot first!\n";
                    break;
                }
                Robot* enemy = generateRandomRobot();
                Weapon* enemyWeapon = generateRandomWeapon();
                enemy->equipWeapon(enemyWeapon);
                std::cout << "You are playing against " << enemy->getName() << " with a " << enemyWeapon->getName() << "\n";

                Arena arena(player, enemy);
                arena.start();

                delete player;
                player = nullptr;

                delete enemy;
                enemy = nullptr;
                break;
            }
            case 4:{
                std::cout << "Welcome! This is a turn-based combat game with robots!\nYour goal is to kill the enemy robot.\n\n There are three typese of robots:\n1. Tanks, they have a lot of hp but don't deal much damage and they are slow.\n2. Assasins, they are very fast and deal slightly more damage than tanks but don't have a lot of hp.\n3. Snipers, they deal a lot of damage and are faster than tanks, but like assasins, they don't have a lot of hp.\n\nEach type of robot has a special ability they can use:\n1. Tanks can activate a shield, taking less damage next time they're attacked.\n2. Assasins can get an extra round.\n3. Snipers can activate crit, dealing more damage the next attack.\n!IMPORTANT! Using an ability does not end the round!\n\nYou can also equip weapons. There are 3 weapons currently:\n1. The Laser Gun, the laser gun is fast and efficient, but doesn't deal a lot of damage (there is also a small chance of getting 5 energy back when using the laser gun).\n2. The Crossbow, it does more damage than the laser gun and costs more energy (there is a small chance of dealing extra damage).\n3. The Rocket Launcher, it does a lot of damage and costs a lot of energy (it's one-time-use).\n";
                break;
            }
            case 5:{
                running = false;
                break;
            }
            case 6:{
                std::ifstream in("date.txt");
                int hp, energy;
                std::string label;

                in >> label;

                player = createRobotFromFile(in);
                Weapon* pw = createWeaponFromFile(in);
                player->equipWeapon(pw);

                in >> label;
                in >> hp >> energy;

                player->setEnergy(energy);
                player->setHp(hp);

                in >> label;

                Robot* enemy = createRobotFromFile(in);
                Weapon* ew = createWeaponFromFile(in);
                enemy->equipWeapon(ew);

                in >> label;
                in >> hp >> energy;

                enemy->setHp(hp);
                enemy->setEnergy(energy);

                Arena arena(player, enemy);
                arena.start();
                delete player;
                delete enemy;
                break; 
            }
            default:{
                std::cout << "Invalid option\n";
            }
        }
    }

    delete player;
    delete playerWeapon;

    return 0;
}

//save // edge cases //make robot based on class
