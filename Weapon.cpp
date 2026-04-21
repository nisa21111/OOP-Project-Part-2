#include "Weapon.h"
#include "Robot.h"

//WEAPON   

Weapon::Weapon(){
    name = "Default";
    damage = 30;
    energyCost = 40;
}

Weapon::Weapon(std::string name, int dmg, int  ec){
    this -> name = name;
    damage = dmg;
    energyCost = ec;
}

Weapon::Weapon(const Weapon& other){
    name = other.name;
    damage = other.damage;
    energyCost = other.energyCost;
}

Weapon& Weapon::operator=(const Weapon& other){
    if (this != &other){
        name = other.name;
        damage = other.damage;
        energyCost = other.energyCost;
    }
    return *this;
}

Weapon::~Weapon(){}

std::ostream& operator <<(std::ostream& os, const Weapon& w){
    os << "Name: " << w.name << "\n";
    os << "Damage: " << w.damage << "\n";
    os << "Energy Cost: " << w.energyCost << "\n";

    return os;
}

std::istream& operator>>(std::istream& in, Weapon& w){
    std::cout << "Name: ";
    in >> w.name;

    std::cout << "Damage: ";
    in >> w.damage;

    std::cout << "Energy Cost: ";
    in >> w.energyCost;

    return in;
}

//LASER GUN

LaserGun::LaserGun() : Weapon("Laser Gun", 40, 20){}

LaserGun::LaserGun(std::string name) : Weapon(name, 40, 20){}

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

std::istream& operator>>(std::istream& in, LaserGun& l){
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

Crossbow::Crossbow() : Weapon("Crossbow", 50,30){}

Crossbow::Crossbow(std::string name) : Weapon (name, 50,30){}

Crossbow::Crossbow(const Crossbow& other) : Weapon(other){}

Crossbow& Crossbow::operator=(const Crossbow& other){
    if (this != &other){
        Weapon::operator=(other);
    }
    return *this;
}

Crossbow::~Crossbow(){}

std::ostream& operator<<(std::ostream& os, const Crossbow& c){
    os << (const Weapon&)c;
    return os;
}

std::istream& operator>>(std::istream& in, Crossbow& c){
    in >> (Weapon&)c;
    return in;
}

void Crossbow::use(Robot& attacker, Robot& enemy){
    if (attacker.getEenergy() < energyCost){
        std::cout << "Not enough energy!\n";
        return;
    }

    attacker.recoverEnergy(-energyCost);
    enemy.takeDamage(damage);

    std::cout << attacker.getName() << " uses Crossbow and deals " << damage << " damage!\n";
}

//ROCKET LAUNCHER

RocketLauncher::RocketLauncher() : Weapon("Rocket Luncher", 80, 50){used = false;}

RocketLauncher::RocketLauncher(std::string name) : Weapon(name, 80, 50){used = false; }

RocketLauncher::RocketLauncher(const RocketLauncher& other) : Weapon(other){used = other.used; }

RocketLauncher& RocketLauncher::operator=(const RocketLauncher& other){
    if (this != &other){
        Weapon::operator=(other);
        used = other.used;
    }
    return *this;
}

RocketLauncher::~RocketLauncher(){}

std::ostream& operator<<(std::ostream& os, const RocketLauncher& rl){
    os << (const Weapon&)rl;
    return os;
}

std::istream& operator>>(std::istream& in, RocketLauncher& rl){
    in >> (Weapon&)rl;
    return in;
}

void RocketLauncher::use(Robot& attacker, Robot& enemy){
    if (used == true){
        std::cout << "You already used the Rocket Launcher!\n";
        return;
    }

    if (attacker.getEenergy() < energyCost){
        std::cout << "Not enough energy!\n";
        return;
    }

    attacker.recoverEnergy(-energyCost);
    enemy.takeDamage(damage);
    used = true;
    std::cout << attacker.getName() << " uses Rocket Launcher and deals " << damage << " damage! You can no longer use the Rocket Launcher.\n";
}