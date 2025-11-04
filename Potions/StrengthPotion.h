#ifndef STRENGTHPOTION_H
#define STRENGTHPOTION_H

#include "../Potion.h"

class StrengthPotion : public Potion {
public:
    StrengthPotion(); // Constructor declaration
    void use() const override; // use of strength potion
};

#endif // STRENGTHPOTION_H

