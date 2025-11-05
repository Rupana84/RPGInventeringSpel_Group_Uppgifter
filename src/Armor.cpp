#include "Armor.h"
#include "Player.h"
#include <sstream>

// Build a string like: "Shield [Armor] def=5 (equipped)"
std::string Armor::describe() const {
    std::ostringstream os;
    os << name << " [Armor] def=" << defense;
    if (equipped) os << " (equipped)";
    return os.str();
}

// Using an armor means equipping it on the player.
void Armor::use(Player& player) {
    player.equipArmor(this);   // let Player manage current armor
    equipped = true;           // local status flag
}