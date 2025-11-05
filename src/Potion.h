// ifndef for header guard, to prevent multiple inclusions
#ifndef POTION_H
#define POTION_H

#include "Player.h"
#include <string>
#include <iostream>
#include "Item.h"

class Potion : public Item {
    
public:
    // Enumeration for different potion types
    enum PotionType { HEALING, MANA, STRENGTH, SPEED };

    Potion(std::string name, int value) : Item(name, value) {}

    virtual void use(Player & player) = 0; // pure virtual function

    virtual ~Potion() = default; // virtual destructor for proper cleanup
};
#endif // POTION_H