#include "ManaPotion.h"
#include <iostream>
#include <sstream>

void ManaPotion::use(Player&) {
    std::cout << "You used " << getName() << " and restored "
              << getValue() << " mana.\n";
}

std::string ManaPotion::describe() const {
    std::ostringstream os;
    os << getName() << " [Potion] +" << getValue() << " mana";
    return os.str();
}