#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include "../Potion.h"

class HealingPotion : public Potion {
public:
    HealingPotion(); // Constructor declaration
    void use() const override; // use of healing potion
};

#endif // HEALINGPOTION_H