#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include <fstream>

class Weapon;

class Robot{
protected:
    std::string name;
    int hp, speed, damage, energy;
    Weapon* weapon;
    bool isSpecialActive;

public:
    Robot();
    Robot(std::string n, int hp, int sp, int dmg, int en);
    Robot(const Robot& other);
    Robot& operator=(const Robot &other);
    virtual ~Robot();

    friend std::ostream& operator<<(std::ostream& os, const Robot& r);
    friend std::istream& operator>>(std::istream& is, Robot& r);

    virtual void useSpecialAbility() = 0;
    virtual void attack(Robot& enemy) = 0;

    virtual void takeDamage(int amount);
    void recoverEnergy (int amount);
    void equipWeapon (Weapon* w);

    virtual void saveToFile(std::ostream& out) const;
    virtual void loadFromFile (std::istream& in);

    int getHp() const {return hp;}
    std::string getName() const {return name; }
    int getEenergy() const {return energy; }
    Weapon* getWeapon() const {return weapon; }
    int getSpeed() const {return speed;}
    int getDamage() const {return damage;}
    virtual std::string getType() const = 0;
    bool hasSpecialActive() const {return isSpecialActive;}
    void resetSpecialAbility() {isSpecialActive = false;}
    void setHp(int h);
    void setEnergy(int h);

};

#endif