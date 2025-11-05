cmake_minimum_required(VERSION 4.0)
project(RPGInventeringSpel_Group_Uppgifter)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(RPGInventeringSpel_Group_Uppgifter
        src/Armor.cpp
        src/Armor.h
        src/HealingPotion.cpp
        src/HealingPotion.h
        src/Item.h
        src/Main.cpp
        src/ManaPotion.cpp
        src/ManaPotion.h
        src/Player.cpp
        src/Player.h
        src/Potion.cpp
        src/Potion.h
        src/PotionFactory.cpp
        src/PotionFactory.h
        src/SpeedPotion.cpp
        src/SpeedPotion.h
        src/StrengthPotion.cpp
        src/StrengthPotion.h
        src/Weapon.cpp
        src/Weapon.h)
