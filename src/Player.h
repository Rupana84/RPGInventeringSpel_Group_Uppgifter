#ifndef PLAYER.H
#define PLAYER.H
#include <iostream>
#include <vector>
#include "Item.h"
#include "memory"

class Weapon;
class Armor;
class Player{

    private:
    int health;
    std::string name;

    std::vector<Item*> inventory;

    Weapon* equippedWeapon = nullptr;
    Armor* equippedArmor = nullptr;
    //Item* equippedItem = nullptr;

    void cleanupInventory();
    
public:
    const std::string& getName() const { return name; }
    Player(const std::string& playerName, int playerHealth);
    ~Player();

    Player(const Player& other) = delete;
    Player& operator=(const Player& other) = delete;


    void displayStatus() const;
    void takeDamage(int damage);
    
    void addItem(Item* item);
    void useItem(int index);
    void removeItem(int index);

    void equipItem(int index);
    void equipItem(Item* item);

    Item* getItemByIndex(int index);


};


#endif