#include "HealingPotion.h"

HealingPotion::HealingPotion() : Potion("Healing Potion", 50) {}

void HealingPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " health points!" << std::endl;
}