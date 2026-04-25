#include "Sniper.h"

Sniper::Sniper() : Robot("Sniper", 300 ,20, 30, 200){}

Sniper::Sniper(std::string name) : Robot(name, 300, 20, 30, 200){}

Sniper::Sniper(const Sniper& other) : Robot(other){}

Sniper& Sniper::operator=(const Sniper& other){
    if (this != &other){
        Robot::operator=(other);
    }
    return *this;
}

Sniper::~Sniper(){}

std::ostream& operator<<(std::ostream& os, const Sniper& s){
    os << (const Robot&)s;
    return os;
}

std::istream& operator>>(std::istream& is, Sniper& s){
    is >> (Robot&)s;
    return is;
}

void Sniper::saveToFile(std::ostream& out) const{
    out << "Sniper\n";
    Robot::saveToFile(out);
}

void Sniper::loadFromFile(std::istream& in){
    Robot::loadFromFile(in);
}

void Sniper::attack(Robot& enemy){
    if (energy < 10){
        std::cout << "Not enough energy!\n";
        return;
    }
    if (enemy.getHp() < 0)
        throw std::logic_error("Enemy aready dead!");
    energy -= 10;
    if (isSpecialActive){
        int crit = damage*2;
        enemy.takeDamage(crit);
        std::cout << name << " deals double damage! " << enemy.getName() << " is hit for " << damage*2 << "!\n";
        isSpecialActive = false;
    }
    else{
        enemy.takeDamage(damage);
        std::cout << name << " attacks " << enemy.getName() << " for " << damage << " damage!\n";
    }
}

void Sniper::useSpecialAbility(){
    if (energy < 40){
        std::cout << "Not enough energy!\n";
        return;
    }

    energy -= 40;
    isSpecialActive = true;
    std::cout << name << " activates Crit!. Next attack will deal double damage!\n";
}