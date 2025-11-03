#include "StrengthPotion.h"

StrengthPotion::StrengthPotion() : Potion("Strength Potion", 20) {}

void StrengthPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " strength points!" << std::endl;

    // Demonstrating stack allocation
    int temporaryStrength = getValue(); // stack-object
    std::cout << "Temporary strength value on stack: " << temporaryStrength << std::endl;

    // Demonstrating heap allocation
    int* heapStrength = new int(getValue()); // heap-object
    std::cout << "Temporary strength value on heap: " << *heapStrength << std::endl;

    delete heapStrength; // Delete heap-object to prevent memory leak
}