#include "Tank.h"

Tank::Tank() : Robot("Tank", 600, 10, 15, 200){}

Tank::Tank(std::string name) : Robot(name, 600, 10, 15, 200){}

Tank::Tank(const Tank& other) : Robot(other){}

Tank& Tank::operator=(const Tank& other){
    if (this != &other){
            Robot::operator=(other);
    }
    return *this;
}

Tank::~Tank(){}

std::ostream& operator<<(std::ostream& os, const Tank& t){
    os << (const Robot&)t;
    return os;
}

std::istream& operator>>(std::istream& is, Tank& t){
    is >> (Robot&)t;
    return is;
}

void Tank::saveToFile(std::ostream& out) const {
    out<< "Tank\n";
    Robot::saveToFile(out);
}

void Tank::loadFromFile(std::istream& in){
    Robot::loadFromFile(in);
}

void Tank::attack(Robot& enemy){
    if (energy < 10){
        std::cout << "Not enough energy!\n";
        return;
    }

    energy -= 10;
    if (enemy.getHp() < 0)
        throw std::logic_error("Enemy already dead");
    enemy.takeDamage(damage);
    std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!\n";
}

void Tank::useSpecialAbility(){
    if (energy < 40){
        std::cout << "Not enough energy!\n";
        return;
    }

    energy -= 40;
    isSpecialActive = true;

    std::cout << name << " activated shield! (takes reduced damage next hit)\n";
}

void Tank::takeDamage(int amount){
    if (amount < 0)
        throw std::invalid_argument("Damage cannot be negative");
    if (isSpecialActive == true){
        amount /= 2;
        isSpecialActive = false;
    }
    Robot::takeDamage(amount);
}