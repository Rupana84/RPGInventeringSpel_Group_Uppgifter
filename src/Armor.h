//
// Created by Gavy Singh on 2025-11-03.
//

#ifndef GAMEGROUP_PROJECT_ARMOR_H
#define GAMEGROUP_PROJECT_ARMOR_H
#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <string>

// The Armor class represents protective gear the player can wear.
// It inherits from Item and adds defense-related attributes.
class Armor : public Item {
    
    int defense;        // How much protection it provides
    bool equipped{false}; // True if this armor is currently being worn

public:
    // Constructor: sets the armor name and defense value when created.
    Armor(const std::string& n, int def) 
    : Item(n,def),defense(def) {}

    // Returns the armor's name.
    const std::string& getName() const override { return Item::getName(); }

    // Returns the item type as "Armor".
    std::string getType() const override { return "Armor"; }

    // Builds and returns a text description of the armor.
    std::string describe() const override;

    // Defines what happens when the player uses this armor.
    // It equips the armor.
    void use(Player& player) override;

    // Returns how much defense this armor adds.
    int getDefense() const { return defense; }

    // Checks if the armor is equipped.
    bool isEquipped() const { return equipped; }

    // Sets the equipped state (true or false).
    void setEquipped(bool v) { equipped = v; }
};

#endif // ARMOR_H
#endif //GAMEGROUP_PROJECT_ARMOR_H