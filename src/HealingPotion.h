#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include "Potion.h"

class HealingPotion : public Potion {
public:
    HealingPotion(); // Constructor declaration
    void use(Player & player) override; // use of healing potion

    std::string getType() const override; 
    std::string describe() const override;
};

#endif // HEALINGPOTION_H