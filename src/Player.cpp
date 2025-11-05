#include "Player.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "weapon.h"
#include "armor.h"

void Player::cleanupInventory(){
    std::cout << "DEBUG: Manually cleaning up " << inventory.size() << " items..." << std::endl;

    for (Item* item : inventory) {
        if(item){
            delete item;
        }
    }
    inventory.clear();

    equippedWeapon = nullptr;
    equippedArmor = nullptr;
}
Player :: ~Player(){
    std ::cout <<"Player" << name << "destructed. Cleaning up inventory..." << std::endl;
    cleanupInventory();
}

Player::Player(const std::string& playerName, int playerHealth)
    : name(playerName), health(playerHealth) {
        std::cout << "Player " << name << " constructed with " << health << " health." << std::endl;
}

void Player::displayStatus() const{
    std::cout << "Player: " << name << ", Health: " << health << std::endl;
    std::cout << "Inventory (" << inventory.size() << " items):" << std::endl;
    std::cout << "Equipped Items: " << (equippedItem ? equippedItem->getName() : "None") << std::endl;

    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ": " << inventory[i]->getName() << " (Value: " << inventory[i]->getValue() << ")" << std::endl;
    }
}
void Player::takeDamage(int damage){
    health -= damage;
    if(health < 0) health = 0;
    std::cout << name << " took " << damage << " damage. Current health: " << health << std::endl;
}
void Player::addItem(Item* item){
    inventory.push_back(item);
    std::cout << "Added item: " << item->getName() << " to " << name << "'s inventory." << std::endl;
}
void Player::useItem(int index){
    if(index < 0 || index >= static_cast<int>(inventory.size())){
        std::cout << "Invalid item index." << std::endl;
        return;
    }
    Item* item = inventory[index];
    if(item){
        item->use();
    }
}
void Player::removeItem(int index){

    if(index < 0 || index >= static_cast<int>(inventory.size())){
        std::cout << "Invalid item index." << std::endl;
        return;
    }

    Item* item = inventory[index];

    if ( equippedWeapon == item){
        equippedWeapon = nullptr;
        std::cout << name << " unequipped item: " << item->getName() << " as it is being removed." << std::endl;
    }
    if (equippedArmor == item){
        equippedArmor = nullptr;
        std::cout << name << " unequipped armor: " << item->getName() << " as it is being removed." << std::endl;
    }


    std::cout << "Removing item: " << item->getName() << " from inventory." << std::endl;
    delete item; 

    inventory.erase(inventory.begin() + index);
}
void Player::equipItem(int index){

    Item* item = inventory[index];
    
    if(Weapon* weapon = dynamic_cast<Weapon*>(item)){
        equippedWeapon = weapon; 
        std::cout << name << " equipped weapon: " << weapon->getName() << std::endl;
    } else if(Armor* armor = dynamic_cast<Armor*>(item)){
        equippedArmor = armor; 
        std::cout << name << " equipped armor: " << armor->getName() << std::endl;
    } else {
        std::cout << "Item is neither a weapon nor armor. Cannot equip." << std::endl;
    }
}
