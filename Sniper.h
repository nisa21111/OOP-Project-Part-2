#ifndef SNIPER_H
#define SNIPER_H

#include "Robot.h"

class Sniper : public Robot{
public:
    Sniper();
    Sniper(std::string name);
    Sniper(const Sniper& other);
    Sniper& operator=(const Sniper& other);
    ~Sniper();

    friend std::ostream& operator<<(std::ostream& os, const Sniper& s);
    friend std::istream& operator>>(std::istream& is, Sniper& s);

    void saveToFile(std::ostream& out) const override;
    void loadFromFile ( std::istream& in) override;

    void attack(Robot& enemy) override;
    void useSpecialAbility() override;
};

#endif;