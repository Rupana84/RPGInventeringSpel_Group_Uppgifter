#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H

#include "Potion.h"

class StrengthPotion : public Potion {
public:
    StrengthPotion(); // Constructor declaration
    void use(Player& player) override; // use of strength potion

    std::string getType() const override; 
    std::string describe() const override;
};

#endif // STRENGTHPOTION_H

