#include "Robot.h"

Robot::Robot(){
    name = "Default";
    hp = 300;
    speed = 20;
    damage = 20;
}

Robot::Robot(std::string n, int hp, int sp, int dmg){
    this -> name = name;
    this -> hp = hp;
    this -> speed = sp;
    this -> damage = dmg;
}

Robot::Robot(const Robot& other) {
    this -> name = other.name;
    this -> hp = other.hp;
    this -> speed = other.speed;
    this -> damage = other.damage;

    if (other.weapon != nullptr)
        this -> weapon = new Weapon(*other.weapon);
    else
        this -> weapon = nullptr;
}

Robot& Robot::operator=(const Robot& other){
    if (this != &other){
        delete this -> weapon;
        this -> name = other.name;
        this -> hp = other.hp;
        this -> speed = other.speed;
        this -> damage = other.damage;

        if (other.weapon != nullptr)
            this -> weapon = new Weapon (*other.weapon);
        else
            this ->weapon = nullptr;
    }
    return *this;
}

Robot::~Robot(){
    delete weapon;
}

