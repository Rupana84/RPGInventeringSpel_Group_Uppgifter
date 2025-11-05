#include "ManaPotion.h"

ManaPotion::ManaPotion() : Potion("Mana Potion", 30) {}

void ManaPotion::use() const {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " mana points!" << std::endl;

    // Demonstrating stack allocation
    int temporaryMana = getValue(); // stack-object
    std::cout << "Temporary mana value on stack: " << temporaryMana << std::endl;

    // Demonstrating heap allocation
    int* heapMana = new int(getValue()); // heap-object
    std::cout << "Temporary mana value on heap: " << *heapMana << std::endl;

    delete heapMana; // Delete heap-object to prevent memory leak
}
