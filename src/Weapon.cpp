#include "Weapon.h"
#include "Player.h"
#include <sstream>

// Builds a text description of the weapon.
// Example output: "Sword [Weapon] dmg=10 (equipped)"
std::string Weapon::describe() const {
    std::ostringstream os;
    os << name << " [Weapon] dmg=" << damage;
    if (equipped) os << " (equipped)";
    return os.str();
}

// Defines what happens when the player uses this weapon.
// Instead of consuming it, it equips the weapon.
void Weapon::use(Player& player) {
    player.equipWeapon(this);
    equipped = true; // mark as equipped
}