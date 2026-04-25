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
    if (hp <= 0 || sp < 0 || dmg < 0 || en < 0)
        throw std::invalid_argument("Invalid robot stats");
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
    if (hp < 0)
        throw std::invalid_argument("HP cannot be negative");
    hp = h;
}

void Robot::setEnergy(int e){
    if (e < 0)
        throw std::invalid_argument("Energy cannot be negative");
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
    if (amount < 0)
        throw std::invalid_argument("Damage cannot be negative");
    hp -= amount;
    if (hp < 0) hp = 0;
 }

void Robot::recoverEnergy(int amount){
    if (energy + amount < 0)
        energy = 0;
    else
        energy+=amount;
}

void Robot::equipWeapon(Weapon* w){
    if (w == nullptr)
        throw std::invalid_argument("Weapon cannot be null");
    if (weapon != w)
        delete weapon;
    weapon = w;
}

void Robot::saveToFile(std::ostream& out) const {
    out << name << "\n";
    out << hp << " " << damage << " " << speed << " " << energy << "\n";

}

void Robot::loadFromFile(std::istream& in){
    if (!(in >> name >> hp >> damage >> speed >> energy))
        throw std::runtime_error("Invalid robot file fromat");

    if (hp < 0 || speed < 0 || damage < 0 || energy < 0)
        throw std::runtime_error("Corrupted robot data");
}

