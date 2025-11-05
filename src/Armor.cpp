//
// Created by Gavy Singh on 2025-11-03.
//
#include "Armor.h"
#include "Player.h"
#include <sstream>

// Returns a string description of the armor.
// Example: "Shield [Armor] def=5 (equipped)"
std::string Armor::describe() const {
    std::ostringstream os;
    os << getName() << " [Armor] def=" << getValue();

    // Add "(equipped)" if this armor is currently worn.
    if (equipped)
        os << " (equipped)";

    return os.str();
}

// Defines what happens when the player uses this armor.
// When used, it tells the Player to equip this armor.
void Armor::use(Player& player) {
    player.equipItem(this);
}