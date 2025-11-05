#include "PotionFactory.h"
#include "HealingPotion.h" // Dessa inkluderingar behövs för new HealingPotion()
#include "ManaPotion.h"
#include "StrengthPotion.h"
#include "SpeedPotion.h"

// Factory methods for creating potions on heap (returns raw pointers)
Potion* PotionFactory::createHealing() {
    // Fungerar bara när HealingPotion inte längre är abstrakt!
    return new HealingPotion();
}

Potion* PotionFactory::createMana() {
    return new ManaPotion();
}

Potion* PotionFactory::createStrength() {
    return new StrengthPotion();
}

Potion* PotionFactory::createSpeed() {
    return new SpeedPotion();
}

// Create potion by type enum
Potion* PotionFactory::createPotion(Potion::PotionType type) {
    switch (type) {
        case Potion::HEALING:
            return createHealing();
        case Potion::MANA:
            return createMana();
        case Potion::STRENGTH:
            return createStrength();
        case Potion::SPEED:
            return createSpeed();
        default:
            return nullptr;
    }
}