#ifndef SPEEDPOTION_H
#define SPEEDPOTION_H

#include "Potion.h"

class SpeedPotion : public Potion {
public:
    explicit SpeedPotion(int amount = 10)
        : Potion("Speed Potion", amount) {}
    void use(Player& player) override;              // prints demo info
    std::string describe() const override;
    std::string getType()  const override { return "Potion"; }
};
#endif