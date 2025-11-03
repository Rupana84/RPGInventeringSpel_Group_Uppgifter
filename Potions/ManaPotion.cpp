#include "ManaPotion.h"

ManaPotion::ManaPotion() : Potion("Mana Potion", 30) {}

void ManaPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " mana points!" << std::endl;
}
