// ifndef for header guard, to prevent multiple inclusions
#ifndef POTION_H
#define POTION_H

#include <string>
#include <iostream>

class Potion {
    
protected:
    std::string name;
    int value; //health, mana, strength, speed

public:
    // Enumeration for different potion types
    enum PoptionType { HEALING, MANA, STRENGTH, SPEED };

    Potion(std::string name, int value) : name(name), value(value) {}

    virtual void use() = 0; // pure virtual function

    std::string getName() const {
        return name;
    }

    int getValue() const {
        return value;
    }

    virtual ~Potion() = default; // virtual destructor for proper cleanup
};
#endif // POTION_H