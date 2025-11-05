#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include <iostream>

Player::Player(const std::string& playerName, int playerHealth)
    : health(playerHealth), name(playerName) {  // init in member order
    std::cout << "Player " << name << " constructed with " << health << " health.\n";
}

Player::~Player() {
    std::cout << "Player " << name << " destructed. Cleaning up inventory...\n";
    for (auto* it : inventory) delete it;
    inventory.clear();
    equippedWeapon = nullptr;
    equippedArmor  = nullptr;
}

void Player::displayStatus() const {
    std::cout << "Player: " << name << ", Health: " << health << "\n";
    std::cout << "Equipped Weapon: "
              << (equippedWeapon ? equippedWeapon->getName() : "None") << "\n";
    std::cout << "Equipped Armor: "
              << (equippedArmor ? equippedArmor->getName() : "None") << "\n";
    std::cout << "Inventory (" << inventory.size() << " items):\n";
    for (std::size_t i = 0; i < inventory.size(); ++i)
        std::cout << "  " << i << ": " << inventory[i]->describe() << "\n";
}

void Player::listItems() const {                      // <-- add this
    std::cout << "Inventory (" << inventory.size() << " items):\n";
    for (std::size_t i = 0; i < inventory.size(); ++i)
        std::cout << "  " << i << ": " << inventory[i]->describe() << "\n";
}

void Player::heal(int amount) {
    if (amount <= 0) return;
    health += amount;
    std::cout << name << " healed " << amount
              << ". Current health: " << health << std::endl;
}

void Player::takeDamage(int damage) {
    health -= damage;
    if (health < 0) health = 0;
    std::cout << name << " took " << damage << " damage. Health: " << health << "\n";
}

void Player::addItem(Item* item) {
    if (item) {
        inventory.push_back(item);
        std::cout << "Added: " << item->getName() << " to " << name << "'s inventory.\n";
    }
}

bool Player::removeItemByIndex(std::size_t idx) {
    if (idx >= inventory.size()) return false;
    Item* item = inventory[idx];
    if (item == equippedWeapon) equippedWeapon = nullptr;
    if (item == equippedArmor)  equippedArmor  = nullptr;
    delete item;
    inventory.erase(inventory.begin() + static_cast<std::ptrdiff_t>(idx));
    return true;
}

void Player::useItem(std::size_t idx) {
    if (idx >= inventory.size()) {
        std::cout << "Invalid index.\n";
        return;
    }
    inventory[idx]->use(*this);
}

void Player::equipItem(int index) {
    if (index < 0 || static_cast<std::size_t>(index) >= inventory.size()) {
        std::cout << "Invalid index.\n";
        return;
    }
    Item* item = inventory[static_cast<std::size_t>(index)];
    if (auto* w = dynamic_cast<Weapon*>(item)) {
        equippedWeapon = w;
        std::cout << name << " equipped weapon: " << w->getName() << "\n";
    } else if (auto* a = dynamic_cast<Armor*>(item)) {
        equippedArmor = a;
        std::cout << name << " equipped armor: " << a->getName() << "\n";
    } else {
        std::cout << "Cannot equip this item.\n";
    }
}

Item* Player::getItemByIndex(int index) {
    if (index < 0 || static_cast<std::size_t>(index) >= inventory.size()) return nullptr;
    return inventory[static_cast<std::size_t>(index)];
}

void Player::equipWeapon(Weapon* w) { equippedWeapon = w; }
void Player::equipArmor(Armor* a)   { equippedArmor  = a; }