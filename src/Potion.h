#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
public:
    enum PotionType { HEALING, MANA, STRENGTH, SPEED };

    using Item::Item;                // inherit Item(name,value) ctor
    virtual void use(Player& player) override = 0;

    virtual ~Potion() = default;
};

#endif // POTION_H