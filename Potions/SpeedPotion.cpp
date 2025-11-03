#include "SpeedPotion.h"

SpeedPotion::SpeedPotion() : Potion("Speed Potion", 15) {}

void SpeedPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " speed points!" << std::endl;
}