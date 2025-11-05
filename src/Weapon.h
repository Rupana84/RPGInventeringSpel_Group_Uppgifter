#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"

class Player; // Forward declaration to avoid circular include

// The Weapon class represents a weapon the player can equip or use.
class Weapon : public Item {
private:
    std::string name;     // Weapon name, e.g., "Sword"
    int damage;           // Weapon damage value
    bool equipped{false}; // True if currently equipped

public:
    explicit Weapon(const std::string& n, int dmg) : name(n), damage(dmg) {}
    ~Weapon() override = default;

    // Implementation of Item interface
    std::string getName()  const override { return name; }
    std::string getType()  const override { return "Weapon"; }
    std::string describe() const override;
    void use(Player& player) override; // equips this weapon

    // Weapon-specific accessors
    int  getDamage()   const { return damage; }
    bool isEquipped()  const { return equipped; }
    void setEquipped(bool v) { equipped = v; }
};

#endif // WEAPON_H