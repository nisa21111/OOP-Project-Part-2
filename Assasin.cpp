#include "Assasin.h"

Assasin::Assasin() : Robot("Assasin", 300, 30, 20, 200){}

Assasin::Assasin(std::string name) : Robot(name, 300, 30, 20, 200){}

Assasin::Assasin(const Assasin& other) : Robot(other){}

Assasin& Assasin::operator=(const Assasin& other){
    if (this != &other){
            Robot::operator=(other);
    }
    return *this;
}

Assasin::~Assasin(){}

std::ostream& operator<<(std::ostream& os, const Assasin& t){
    os << (const Robot&)t;
    return os;
}

std::istream& operator>>(std::istream& is, Assasin& t){
    is >> (Robot&)t;
    return is;
}

void Assasin::saveToFile(std::ostream& out) const{
    out << "Assasin\n";
    Robot::saveToFile(out);

}

void Assasin::loadFromFile(std::istream& in){
    Robot::loadFromFile(in);
}

void Assasin::attack(Robot& enemy){
    if (energy < 10){
        std::cout<< " Not enough energy!\n";
        return;
    }
    energy -= 10;
    enemy.takeDamage(damage);
    std::cout << name << " attacks for "<< damage << " damage!\n";
    if (isSpecialActive == true){
        enemy.takeDamage(damage);
        std::cout << name << " deals the second attack for " << damage << " damage!\n";
        isSpecialActive = false;
    }
}

void Assasin::useSpecialAbility(){
    if (energy < 40 ){
        std::cout << "Not enough energy!\n";
        return;
    }

    energy -= 40;
    isSpecialActive = true;
    std::cout << "Next attack will be double!\n";
}