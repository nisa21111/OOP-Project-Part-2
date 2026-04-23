#ifndef WEAPON_H
#define WEAPON_H


#include <iostream>
#include <string>
#include <fstream>

class Robot;

class Weapon {
protected:
    std::string name;
    int damage;
    int energyCost;

public:
    Weapon();
    Weapon(std::string name, int dmg, int ec);
    virtual ~Weapon();
    Weapon(const Weapon& other);
    Weapon& operator=(const Weapon& other);

    friend std::ostream& operator<<(std::ostream& os, const Weapon& w);
    friend std::istream& operator>>(std::istream& in, Weapon& w);

    virtual void use(Robot& attacker, Robot& enemy) = 0;

    std::string getName() const {return name;}
    int getDamage() const {return damage;}
    int getEnergyCost() const {return energyCost;}
};

class LaserGun : public Weapon {
public:
    LaserGun();
    LaserGun(std::string name);
    LaserGun(const LaserGun& other);
    LaserGun& operator=(const LaserGun& other);
    ~LaserGun();

    friend std::ostream& operator<<(std::ostream& os, const LaserGun& l);
    friend std::istream& operator>>(std::istream& in, LaserGun& l);

    void use(Robot& attacker, Robot& enemy) override;
};

class Crossbow : public Weapon{
public:
    Crossbow();
    Crossbow(std::string name);
    Crossbow(const Crossbow& other);
    Crossbow& operator=(const Crossbow& other);
    ~Crossbow();

    friend std::ostream& operator<<(std::ostream& os, const Crossbow& c);
    friend std::istream& operator>>(std::istream& in, Crossbow& c);

    void use(Robot& attacker, Robot& enemy) override;
};

class RocketLauncher : public Weapon{
private:
    bool used;
public:
    RocketLauncher();
    RocketLauncher(std::string name);
    RocketLauncher(const RocketLauncher& other);
    RocketLauncher& operator=(const RocketLauncher& other);
    ~RocketLauncher();

    friend std::ostream& operator<<(std::ostream& os, const RocketLauncher& rl);
    friend std::istream& operator>>(std::istream& in, RocketLauncher& rl);

    void use(Robot& attacker, Robot& enemy) override;
};


#endif