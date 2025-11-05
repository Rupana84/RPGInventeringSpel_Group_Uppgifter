#ifndef POTIONFACTORY_H
#define POTIONFACTORY_H

#include "HealingPotion.h"
#include "ManaPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"

struct PotionFactory {
    static Potion* createHealing();
    static Potion* createMana();
    static Potion* createStrength();
    static Potion* createSpeed();
};
#endif