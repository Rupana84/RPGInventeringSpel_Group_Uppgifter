#include "HealingPotion.h"

HealingPotion::HealingPotion() : Potion("Healing Potion", 50) {}

void HealingPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " health points!" << std::endl;

    // Demonstrating stack allocation
    int temporaryHealth = getValue(); // stack-object
    std::cout << "Temporary healing value on stack: " << temporaryHealth << std::endl;

    // Demonstrating heap allocation
    int* heapHealth = new int(getValue()); // heap-object
    std::cout << "Temporary healing value on heap: " << *heapHealth << std::endl;

    delete heapHealth; // Delete heap-object to prevent memory leak
}