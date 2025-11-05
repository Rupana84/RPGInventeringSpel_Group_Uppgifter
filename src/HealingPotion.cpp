#include "HealingPotion.h"
class Player; 

HealingPotion::HealingPotion() : Potion("Healing Potion", 50) {}

void HealingPotion::use(Player& player) { 
    std::cout << "You used a " << getName() << " and restored " << getValue() << " healthpoints!" << std::endl;
    
    int temporaryHealth = getValue();
    std::cout << "Temporary healing value on stack: " << temporaryHealth << std::endl;
    int* heapHealth = new int(getValue());
    std::cout << "Temporary healing value on heap: " << *heapHealth << std::endl;
    delete heapHealth; 
}
std::string HealingPotion::getType() const {
    return "Potion";
}


std::string HealingPotion::describe() const {
    return getName() + " | Returned health : " + std::to_string(getValue()) + ".";
}