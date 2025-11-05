#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player; // forward declaration

class Item {
protected:
    std::string name_;
    int value_{0};

public:
    Item() = default;
    Item(std::string name, int value) : name_(std::move(name)), value_(value) {}
    virtual ~Item() = default;

    // Basic API used across the project
    virtual std::string getName()  const { return name_; }
    virtual int         getValue() const { return value_; }

    // Common polymorphic interface
    virtual std::string describe() const = 0;
    virtual std::string getType()  const = 0;
    virtual void use(Player& player) = 0;
};

#endif // ITEM_H