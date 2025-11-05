#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H

// Korrekta sökvägar utan 'Potions/'
#include "Potion.h"
#include "ManaPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"
#include "HealingPotion.h"


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