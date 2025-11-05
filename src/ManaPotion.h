#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "Potion.h"

class ManaPotion : public Potion {
public:
    explicit ManaPotion(int amount = 40)
        : Potion("Mana Potion", amount) {}
    void use(Player& player) override;              // prints demo info
    std::string describe() const override;
    std::string getType()  const override { return "Potion"; }
};
#endif