#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

// Abstrakt basklass
class Item {
protected:
    std::string name;
    int value;

public:
    Item(const std::string& name, int value);
    virtual ~Item(); // Virtuell destruktor 

    // Virtuella funktioner för polymorfism

    // virtuell funktion (Abstrakt)
    virtual void use() const = 0;

    const std::string& getName() const;
    int getValue() const;
};

#endif // ITEM_H