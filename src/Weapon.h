//
// Created by Gavy Singh on 2025-11-03.
//

#ifndef GAMEGROUP_PROJECT_WEAPON_H
#define GAMEGROUP_PROJECT_WEAPON_H

#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <string>

// The Weapon class represents any weapon the player can use.
// It inherits from the base class Item and adds weapon-specific details.
class Weapon : public Item {
    std::string name;   // The weapon's name, e.g., "Sword"
    int damage;         // How much damage this weapon can deal
    bool equipped{false}; // Tracks whether the weapon is currently equipped

public:
    // Constructor: sets the name and damage when a weapon is created.
    Weapon(const std::string& n, int dmg) : name(n), damage(dmg) {}

    // Returns the weapon's name.
    std::string getName() const override { return name; }

    // Returns the item type as "Weapon".
    std::string getType() const override { return "Weapon"; }

    // Returns a short description of the weapon.
    std::string describe() const override;

    // Defines what happens when the player uses the weapon.
    // In this case, it equips the weapon.
    void use(Player& player) override;

    // Returns how much damage this weapon provides.
    int getDamage() const { return damage; }

    // Checks if this weapon is equipped.
    bool isEquipped() const { return equipped; }

    // Sets the equipped status.
    void setEquipped(bool v) { equipped = v; }
};

#endif // WEAPON_H

#endif //GAMEGROUP_PROJECT_WEAPON_H