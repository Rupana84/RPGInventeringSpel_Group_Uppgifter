#include "HealingPotion.h"
#include "Player.h"
#include <iostream>
#include <sstream>

void HealingPotion::use(Player& player) {
    std::cout << "You used " << getName() << " and restored "
              << getValue() << " HP.\n";
    player.heal(getValue());
}

std::string HealingPotion::describe() const {
    std::ostringstream os;
    os << getName() << " [Potion] +" << getValue() << " HP";
    return os.str();
}