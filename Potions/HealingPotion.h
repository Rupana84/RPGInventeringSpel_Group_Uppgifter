#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include "Potion.h"

class HealingPotion : public Potion {
public:
    explicit HealingPotion(int amount = 50)
        : Potion("Healing Potion", amount) {}
    void use(Player& player) override;
    std::string describe() const override;
    std::string getType()  const override { return "Potion"; }
};
#endif