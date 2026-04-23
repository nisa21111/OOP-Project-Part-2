#ifndef ASSASIN_H
#define ASSASIN_H

#include "Robot.h"

class Assasin : public Robot{
public:
    Assasin();
    Assasin(std::string name);
    Assasin(const Assasin& other);
    Assasin& operator=(const Assasin& other);
    ~Assasin();

    friend std::ostream& operator<<(std::ostream& os, const Assasin& t);
    friend std::istream& operator>>(std::istream& is, Assasin& t);

    void saveToFile(std::ostream& out) const override;
    void loadFromFile (std::istream& in) override;

    void attack(Robot& enemy) override;
    void useSpecialAbility () override;

    std::string getType() const override {return "Assasin";}
};

#endif