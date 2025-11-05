#ifndef SPEEDPOTION_H
#define SPEEDPOTION_H

#include "../Potion.h"

class SpeedPotion : public Potion {
public:
    SpeedPotion(); // Constructor declaration
    void use() const override; // use of speed potion
};

#endif // SPEEDPOTION_H