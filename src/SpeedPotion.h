#ifndef SPEEDPOTION_H
#define SPEEDPOTION_H

#include "Potion.h"

class SpeedPotion : public Potion {
public:
    SpeedPotion(); // Constructor declaration
    void use(Player& player) override; // use of speed potion

    std::string getType() const override; 
    std::string describe() const override;
};

#endif // SPEEDPOTION_H