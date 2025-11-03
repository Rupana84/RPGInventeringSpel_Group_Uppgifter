#include "SpeedPotion.h"

SpeedPotion::SpeedPotion() : Potion("Speed Potion", 15) {}

void SpeedPotion::use() {
    std::cout << "You used a " << getName() << " and restored " << getValue() << " speed points!" << std::endl;

    // Demonstrating stack allocation
    int temporarySpeed = getValue(); // stack-object
    std::cout << "Temporary speed value on stack: " << temporarySpeed << std::endl;

    // Demonstrating heap allocation
    int* heapSpeed = new int(getValue()); // heap-object
    std::cout << "Temporary speed value on heap: " << *heapSpeed << std::endl;

    delete heapSpeed; // Delete heap-object to prevent memory leak
}