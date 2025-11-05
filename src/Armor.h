#ifndef ARMOR_H
#define ARMOR_H

#include <string>
#include "Item.h"

class Player; // forward declaration

// Protective gear item.
class Armor : public Item {
private:
    std::string name;     // e.g. "Steel Shield"
    int  defense;         // defense value
    bool equipped{false}; // worn status

public:
    explicit Armor(const std::string& n, int def) : name(n), defense(def) {}
    ~Armor() override = default;

    // Item interface
    std::string getName()  const override { return name; }
    std::string getType()  const override { return "Armor"; }
    std::string describe() const override;
    void use(Player& player) override;      // equips this armor

    // Armor-specific
    int  getDefense() const { return defense; }
    bool isEquipped() const { return equipped; }
    void setEquipped(bool v) { equipped = v; }
};

#endif // ARMOR_H