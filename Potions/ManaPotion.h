#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "../Potion.h"

class ManaPotion : public Potion {
public:
    ManaPotion(); // Constructor declaration
    void use() const override; // use of mana potion
};

#endif // MANAPOTION_H