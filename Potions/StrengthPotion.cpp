#include "StrengthPotion.h"

StrengthPotion::StrengthPotion() : Potion("Strength Potion", 20) {}

void StrengthPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " strength points!" << std::endl;
}