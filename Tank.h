#ifndef TANK_H
#define TANK_H

#include "Robot.h"

class Tank : public Robot{
public:
    Tank();
    Tank(std::string name);
    Tank(const Tank& other);
    Tank& operator=(const Tank& other);
    ~Tank();

    friend std::ostream& operator<<(std::ostream& os, const Tank& t);
    friend std::istream& operator>>(std::istream& is, Tank& t);

    void saveToFile(std::ostream& out) const override;
    void loadFromFile (std::istream& in) override;

    void attack(Robot& enemy) override;
    void useSpecialAbility () override;
    void takeDamage(int amount) override;

    std::string getType() const override {return "Sniper";}
};

#endif