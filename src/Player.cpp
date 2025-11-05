#include "Player.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

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

void Player::displayStatus() const {
    std::cout << "Player: " << name << ", Health: " << health << std::endl;
    
    std::cout << "Equipped Weapon: " << (equippedWeapon ? equippedWeapon->getName() : "None") << std::endl;
    std::cout << "Equipped Armor: " << (equippedArmor ? equippedArmor->getName() : "None") << std::endl; 
    
    std::cout << "Inventory (" << inventory.size() << " items):" << std::endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << i << ": " << inventory[i]->describe() << std::endl; 
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
        item->use(*this); 
        
        if (dynamic_cast<Potion*>(item)) {
            removeItem(index); 
            std::cout << item->getName() << " har förbrukats." << std::endl;
            
        }
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
void Player::equipItem(Item* item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    
    if (it != inventory.end()) {
        int index = std::distance(inventory.begin(), it);
        
        Player::equipItem(index);
    } else {
        std::cout << "Could not equip object: Object was not found in inventory." << std::endl;
    }
}
void Player::equipItem(int index) {
    if (index < 0 || index >= static_cast<int>(inventory.size())) {
        std::cout << "Invalid item index for equipping." << std::endl;
        return;
    }

    Item* item = inventory[index];
    
    Weapon* weapon = dynamic_cast<Weapon*>(item);
    if (weapon) {
        if (equippedWeapon) {
            equippedWeapon->setEquipped(false);
            std::cout << equippedWeapon->getName() << " unequipped." << std::endl;
        }

        equippedWeapon = weapon;
        equippedWeapon->setEquipped(true);
        std::cout << name << " equipped weapon: " << equippedWeapon->getName() << std::endl;
        return;
    }

    Armor* armor = dynamic_cast<Armor*>(item);
    if (armor) {
        if (equippedArmor) {
            equippedArmor->setEquipped(false);
            std::cout << equippedArmor->getName() << " unequipped." << std::endl;
        }

        equippedArmor = armor;
        equippedArmor->setEquipped(true);
        std::cout << name << " equipped armor: " << equippedArmor->getName() << std::endl;
        return;
    }

    std::cout << item->getName() << " cannot be equipped." << std::endl;
}

Item* Player::getItemByIndex(int index) {
    if (index >= 0 && index < inventory.size()) {
        return inventory[index];
    }
    return nullptr;
}