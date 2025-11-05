#include "StrengthPotion.h"
#include <iostream>
#include <sstream>

void StrengthPotion::use(Player&) {
    std::cout << "You used " << getName()
              << " and gained +" << getValue() << " strength.\n";
}

std::string StrengthPotion::describe() const {
    std::ostringstream os;
    os << getName() << " [Potion] +" << getValue() << " STR";
    return os.str();
}