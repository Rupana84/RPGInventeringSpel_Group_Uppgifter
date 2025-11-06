// src/Main.cpp
#include <iostream>
#include <limits>
#include <string>

#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "PotionFactory.h"

static void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static void showMenu() {
    std::cout << "\n=== RPG Inventory ===\n"
              << "1) Add item\n"
              << "2) Show inventory & status\n"
              << "3) Use item\n"
              << "4) Remove item\n"
              << "5) Equip item\n"
              << "0) Exit\n> ";
}

int main() {
    Player player("Hero", 100);

    bool running = true;
    while (running) {
        showMenu();
        int choice;
        if (!(std::cin >> choice)) { clearInput(); continue; }

        switch (choice) {
            case 1: { // Add item
                std::cout << "Add: 1) Weapon  2) Armor  3) Potion  0) Cancel\n> ";
                int type; if (!(std::cin >> type)) { clearInput(); break; }

                if (type == 1) {
                    clearInput();
                    std::string name; int dmg = 0;
                    std::cout << "Weapon name: "; std::getline(std::cin, name);
                    std::cout << "Damage: "; if (!(std::cin >> dmg)) { clearInput(); break; }
                    player.addItem(new Weapon(name, dmg));
                } else if (type == 2) {
                    clearInput();
                    std::string name; int def = 0;
                    std::cout << "Armor name: "; std::getline(std::cin, name);
                    std::cout << "Defense: "; if (!(std::cin >> def)) { clearInput(); break; }
                    player.addItem(new Armor(name, def));
                } else if (type == 3) {
                    std::cout << "Potion: 1) Healing  2) Mana  3) Strength  4) Speed  0) Cancel\n> ";
                    int p; if (!(std::cin >> p)) { clearInput(); break; }
                    Potion* pot = nullptr;
                    if (p == 1) pot = PotionFactory::createHealing();
                    else if (p == 2) pot = PotionFactory::createMana();
                    else if (p == 3) pot = PotionFactory::createStrength();
                    else if (p == 4) pot = PotionFactory::createSpeed();
                    if (pot) { player.addItem(pot); std::cout << pot->getName() << " added.\n"; }
                }
                break;
            }

            case 2: { // Show inventory & status
                player.displayStatus();
                //player.listItems();
                break;
            }

            case 3: { // Use item
                std::cout << "Index to use: ";
                std::size_t idx; if (!(std::cin >> idx)) { clearInput(); break; }
                player.useItem(idx);
                break;
            }

            case 4: { // Remove item
                std::cout << "Index to remove: ";
                std::size_t idx; if (!(std::cin >> idx)) { clearInput(); break; }
                if (!player.removeItemByIndex(idx)) std::cout << "Invalid index.\n";
                break;
            }

            case 5: { // Equip item
                std::cout << "Index to equip: ";
                int idx; if (!(std::cin >> idx)) { clearInput(); break; }
                player.equipItem(idx);
                break;
            }

            case 0:
                running = false;
                break;

            default:
                std::cout << "Invalid choice.\n";
        }
    }

    std::cout << "Goodbye.\n";
    return 0;
}