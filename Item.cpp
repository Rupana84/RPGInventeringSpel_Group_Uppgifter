#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, int value) : name(name), value(value) {}

Item::~Item() {
    // Standarddestruktor, anropas automatiskt
}

const std::string& Item::getName() const {
    return name;
}

int Item::getValue() const {
    return value;
}

void Item::use() const {
    std::cout << "Använder det föremålet: " << name  << std::endl;
}