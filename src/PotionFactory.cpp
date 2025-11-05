#include "PotionFactory.h"

Potion* PotionFactory::createHealing()  { return new HealingPotion(); }
Potion* PotionFactory::createMana()     { return new ManaPotion(); }
Potion* PotionFactory::createStrength() { return new StrengthPotion(); }
Potion* PotionFactory::createSpeed()    { return new SpeedPotion(); }