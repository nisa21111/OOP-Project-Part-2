#include "Weapon.h"
#include "Robot.h"

//WEAPON   

Weapon::Weapon(){
    name = "Default";
    damage = 30;
    energyCost = 40;
    usedOnce = false;
}

Weapon::Weapon(std::string name, int dmg, int  ec, int  otu){
    this -> name = name;
    damage = dmg;
    energyCost = ec;
    usedOnce = otu;
}

Weapon::Weapon(const Weapon& other){
    name = other.name;
    damage = other.damage;
    energyCost = other.energyCost;
    usedOnce = other.usedOnce;
}

Weapon& Weapon::operator=(const Weapon& other){
    if (this != &other){
        name = other.name;
        damage = other.damage;
        energyCost = other.energyCost;
        usedOnce = other.usedOnce;
    }
    return *this;
}

Weapon::~Weapon(){}

std::ostream& operator <<(std::ostream& os, const Weapon& w){
    os << "Name: " << w.name << "\n";
    os << "Damage: " << w.damage << "\n";
    os << "Energy Cost: " << w.energyCost << "\n";
    os << "One Time Use: " << w.usedOnce << "\n";

    return os;
}

std::istream& operator>>(std::istream& in, Weapon& w){
    std::cout << "Name: ";
    in >> w.name;

    std::cout << "Damage: ";
    in >> w.damage;

    std::cout << "Energy Cost: ";
    in >> w.energyCost;

    std::cout << "One Time Use (0/1): ";
    in >> w.usedOnce;

    return in;
}

//LASER GUN

LaserGun::LaserGun() : Weapon("Laser Gun", 40, 20, false){}

LaserGun::LaserGun(std::string name) : Weapon(name, 40, 20, false){}

LaserGun::LaserGun(const LaserGun& other) : Weapon(other){}

LaserGun& LaserGun::operator=(const LaserGun& other){
    if (this != &other){
        Weapon::operator=(other);
    }
    return *this;
}

LaserGun::~LaserGun(){}

std::ostream& operator<<(std::ostream& os, const LaserGun& l){
    os << (const Weapon&)l;
    return os;
}

std::istream& operator>>(std::istream& in, Weapon& l){
    in >> (Weapon&)l;
    return in;
}

void LaserGun::use(Robot& attacker, Robot& enemy){
    if (attacker.getEenergy() < energyCost){
        std::cout << "Not enough energy!\n";
        return;
    }

    attacker.recoverEnergy(-energyCost);
    enemy.takeDamage(damage);

    std::cout << attacker.getName() << " uses Laser Gun and deals " << damage << " damage!\n";
}

//CROSSBOW