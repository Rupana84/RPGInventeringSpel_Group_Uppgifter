Arv & Polymorfi	Basklassen Item används för att lagra alla föremål i std::vector<Item*> inventory. Barnklasserna (Weapon, Armor, Potion) använder virtuella funktioner (use, describe).
Utrustningslogik	Överlagrade funktioner (equipItem) hanterar utrustning. dynamic_cast används för att säkert identifiera och utrusta Weapon eller Armor från en generisk Item*.
Minneshantering	Alla föremål allokeras på Heapen med new. Player-klassen har ägarskap över dessa pekare.
Städar minne	Destruktorn (~Player()) anropar cleanupInventory(), vilken använder delete på alla kvarvarande Item* i inventeringen för att undvika minnesläckor.
Code Structure programmeringssed med Header-filer (.h) och Implementeringsfiler (.cpp) används i hela projektet.

Kompilera (Måste göras efter varje kodändring):
Bash

g++ (Get-ChildItem src\*.cpp).FullName -o my_rpg_game

Kör spelet:
Bash

    .\my_rpg_game

Huvudmeny

Använd menyn för att testa all funktionalitet:

    Val 1: Lägg till föremål (skapande på Heapen).

    Val 3: Använd föremål (Polymorfi och Potion raderas från Heapen).

    Val 5: Utrusta föremål (Polymorfi och dynamic_cast).

    Val 7: Avsluta spelet (Utlöser Destruktor och minnesstädning).
