#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

// Abstrakt basklass
class Player; 
class Item {
protected:
    std::string name;
    int value;

public:
    Item(const std::string& name, int value);
    virtual ~Item(); // Virtuell destruktor 

    // Virtuella funktioner för polymorfism
    virtual const std::string& getName() const { return name; }
    virtual int getValue() const { return value; }


    virtual std::string getType() const = 0; 
    virtual std::string describe() const = 0;
    virtual void use(Player& player) = 0;

};

#endif // ITEM_H