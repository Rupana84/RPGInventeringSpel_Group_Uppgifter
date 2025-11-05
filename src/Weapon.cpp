//
// Created by Gavy Singh on 2025-11-03.
//
#include <iostream>
#include "Weapon.h"
#include "Player.h"
#include <sstream>

// Builds a text description of the weapon.
// Example output: "Sword [Weapon] dmg=10 (equipped)"
std::string Weapon::describe() const {
    std::ostringstream os;
    os << name << " [Weapon] dmg=" << getValue();

    // Add a note if the weapon is currently equipped.
    if (equipped)
        os << " (equipped)";

    return os.str();
}

// Called when the player uses this weapon.
// Instead of consuming it, it tells the Player to equip this weapon.
void Weapon::use(Player& player) {
    player.equipItem(this);

    setEquipped(true); 

    std::cout << player.getName() << " Equipped weapon " << getName() << "." << std::endl;
}
