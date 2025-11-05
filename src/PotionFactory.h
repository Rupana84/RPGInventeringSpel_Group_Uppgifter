#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H

#include "Potion.h"
#include "Potions/HealingPotion.h"
#include "Potions/ManaPotion.h"
#include "Potions/StrengthPotion.h"
#include "Potions/SpeedPotion.h"

class PotionFactory {
public:
    // Factory methods for creating potions on heap (returns raw pointers)
    static Potion* createHealing();
    static Potion* createMana();
    static Potion* createStrength();
    static Potion* createSpeed();
    
    // Create potion by type enum
    static Potion* createPotion(Potion::PotionType type);
};

#endif // POTIONFACTORY_H