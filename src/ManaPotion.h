#ifndef MANAPOTION_H
#define MANAPOTION_H

#include "Potion.h"

class ManaPotion : public Potion {
public:
    ManaPotion(); // Constructor declaration
    void use(Player & player)  override; // use of mana potion

    std::string getType() const override; 
    std::string describe() const override;
};

#endif // MANAPOTION_H