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

    std::vector<Item*> inventory;

    Item* equippedItem = nullptr;
    Item* equippedArmor = nullptr;

    void cleanupInventory();
    
public:
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

    Item* getItemByIndex(int index);


};


#endif