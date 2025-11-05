#include <iostream>
#include <string>
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "PotionFactory.h"

using namespace std;

void showMenu() {
    cout << "\nWelcome to our RPG Inventory System!\n";
    cout << "What would you like to do?\n";
    cout << "1. Add an item to the inventory\n";
    cout << "2. Show all items in inventory\n";
    cout << "3. Use an item\n";
    cout << "4. Remove an item from inventory\n";
    cout << "5. Equip an item\n";
    cout << "6. Show player status\n";
    cout << "7. Exit game\n";
}

int main() {
    Player player("Hero", 100);
    bool running = true;

    while (running) {
        showMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: { // Add item
                cout << "\nWhat would you like to add?\n";
                cout << "1. Weapon\n";
                cout << "2. Armor\n";
                cout << "3. Potion\n";
                cout << "Choice: ";
                int type;
                cin >> type;

                string name;
                int stat;

                if (type == 1) { // Weapon
                    cin.ignore();
                    cout << "Enter weapon name: ";
                    getline(cin, name);
                    cout << "Enter weapon damage: ";
                    cin >> stat;
                    //player.addItem(new Weapon(name, stat));
                } 
                else if (type == 2) { // Armors
                    cin.ignore();
                    cout << "Enter armor name: ";
                    getline(cin, name);
                    cout << "Enter armor defense: ";
                    cin >> stat;
                    //player.addItem(new Armor(name, stat));
                } 
                else if (type == 3) { // Potion
                    cout << "\nChoose potion type:\n";
                    cout << "1. Healing Potion\n";
                    cout << "2. Mana Potion\n";
                    cout << "3. Strength Potion\n";
                    cout << "4. Speed Potion\n";
                    cout << "Choice: ";
                    int potionType;
                    cin >> potionType;

                    Potion* potion = nullptr;
                    switch (potionType) {
                        case 1: potion = PotionFactory::createHealing(); break;
                        case 2: potion = PotionFactory::createMana(); break;
                        case 3: potion = PotionFactory::createStrength(); break;
                        case 4: potion = PotionFactory::createSpeed(); break;
                        default:
                            cout << "Invalid potion type.\n";
                            break;
                    }
                    if (potion) {
                        player.addItem(potion);
                        cout << potion->getName() << " added to inventory.\n";
                    }
                } 
                else {
                    cout << "Invalid item type.\n";
                }
                break;
            }

            case 2: { // Show inventory
                player.displayStatus();
                break;
            }

            case 3: { // Use item
                cout << "Enter the index of the item to use: ";
                int index;
                cin >> index;
                player.useItem(index);
                break;
            }

            case 4: { // Remove item
                cout << "Enter the index of the item to remove: ";
                int index;
                cin >> index;
                player.removeItem(index);
                break;
            }

            case 5: { // Equip item
                cout << "Enter the index of the item to equip: ";
                int index;
                cin >> index;
                player.equipItem(index);
                break;
            }

            case 6: { // Show player status
                player.displayStatus();
                break;
            }

            case 7: { // Exit
                cout << "Exiting game\n";
                running = false;
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    cout << "You exited the game!\n";
    return 0;
}
