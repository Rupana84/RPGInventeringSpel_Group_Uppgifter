#ifndef PLAYER.H
#define PLAYER.H
#include <iostream>
#include <vector>
#include "Item.h"
#include "memory"

class Player{

    private:
    int health;
    std::string name;

    std::vector<std::unique_ptr<Item>> inventory;

    Item* equippedItem = nullptr;
    Item* equippedArmor = nullptr;
    
public:
    Player(const std::string& playerName, int playerHealth);
    ~Player();

    void displayStatus() const;
    void takeDamage(int damage);
    
    void addItem(std::unique_ptr<Item> item);
    void useItem(int index);
    void removeItem(int index);

    void equipItem(int index);

    Item* getItemByIndex(int index);


};


#endif