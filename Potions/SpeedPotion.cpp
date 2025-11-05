#include "SpeedPotion.h"
#include <iostream>
#include <sstream>

void SpeedPotion::use(Player&) {
    std::cout << "You used " << getName()
              << " and gained +" << getValue() << " speed.\n";
}

std::string SpeedPotion::describe() const {
    std::ostringstream os;
    os << getName() << " [Potion] +" << getValue() << " SPD";
    return os.str();
}