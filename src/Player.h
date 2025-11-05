#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <cstddef>

class Item;
class Weapon;
class Armor;

class Player {
private:
    int health;
    std::string name;
    std::vector<Item*> inventory;   // raw pointers per exam
    Weapon* equippedWeapon{nullptr};
    Armor*  equippedArmor{nullptr};

public:
    Player(const std::string& playerName, int playerHealth = 100);
    ~Player();                                // deletes owned Item*

    // status
    const std::string& getName() const { return name; }
    int  getHealth() const { return health; }
    void heal(int amount);
    void takeDamage(int dmg);
    void displayStatus() const;               // <-- add this to match Player.cpp

    // inventory
    void addItem(Item* item);                 // takes ownership
    void listItems() const;
    bool removeItemByIndex(std::size_t idx);  // deletes the item
    void useItem(std::size_t idx);

    // equip
    void equipItem(int index);                // keep teammate API
    void equipWeapon(Weapon* w);              // used by Weapon::use
    void equipArmor(Armor* a);                // used by Armor::use

    Item* getItemByIndex(int index);
};

#endif // PLAYER_H