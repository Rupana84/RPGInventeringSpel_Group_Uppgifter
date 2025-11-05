#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H

#include "Potion.h"

class StrengthPotion : public Potion {
public:
    explicit StrengthPotion(int amount = 10)
        : Potion("Strength Potion", amount) {}
    void use(Player& player) override;              // prints demo info
    std::string describe() const override;
    std::string getType()  const override { return "Potion"; }
};
#endif