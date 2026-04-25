#include "Robot.h"
#include "Weapon.h"

Robot::Robot(){
    name = "Default";
    hp = 300;
    speed = 20;
    damage = 20;
    energy = 200;
    weapon = nullptr;
    isSpecialActive = false;
    weapon = nullptr;
}

Robot::Robot(std::string n, int hp, int sp, int dmg, int en){
    name = n;
    this -> hp = hp;
    speed = sp;
    damage = dmg;
    energy = en;
    weapon = nullptr;
    isSpecialActive = false;
    weapon = nullptr;
}

Robot::Robot(const Robot& other) {
    name = other.name;
    hp = other.hp;
    speed = other.speed;
    damage = other.damage;
    energy = other.energy;
    isSpecialActive = other.isSpecialActive;

    weapon = nullptr;
}

Robot& Robot::operator=(const Robot& other){
    if (this != &other){
        name = other.name;
        hp = other.hp;
        speed = other.speed;
        damage = other.damage;
        energy = other.energy;
        isSpecialActive = other.isSpecialActive;

        weapon = nullptr;
    }
    return *this;
}

Robot::~Robot(){
    delete weapon;
    weapon = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Robot& r){
    os << "Name: " << r.name << "\n";
    os << "HP: " << r.hp << "\n";
    os << "Damage: " << r.damage << "\n";
    os << "Speed: " << r.speed << "\n";
    os << "Energy: " << r.energy << "\n";

    if (r.weapon)
        os << "Weapon equipped\n";
    else
        os << "No weapon equipped\n";

    return os;
}

void Robot::setHp(int h){
    hp = h;
}

void Robot::setEnergy(int e){
    energy = e;
}

std::istream& operator>>(std::istream& is, Robot& r){
    std::cout << "Name: ";
    is >> r.name;

    std::cout << "HP: ";
    is >> r.hp;

    std::cout << "Damage: ";
    is >> r.damage;

    std::cout << "Speed: ";
    is >> r.speed;

    std::cout << "Energy: ";
    is >> r.energy;

    return is;
}

void Robot::takeDamage(int amount){
    hp -= amount;
    if (hp < 0) hp = 0;
 }

void Robot::recoverEnergy(int amount){
    energy+=amount;
}

void Robot::equipWeapon(Weapon* w){
    if (weapon != w)
        delete weapon;
    weapon = w;
}

void Robot::saveToFile(std::ostream& out) const {
    out << name << "\n";
    out << hp << " " << damage << " " << speed << " " << energy << "\n";

}

void Robot::loadFromFile(std::istream& in){
    in >> name;
    in >> hp >> damage >> speed >> energy;
}

