// main.cpp
#include "player.h"
#include "menu.h"
#include "location.h"
#include <iostream>

int main() {
    Player player("Hero", 100, 100, 20);
    player.setLocation(Location("Magnolia Town", {"Goblin", "Green Slime"}));
    Menu menu(player);
    menu.displayMenu();
    return 0;
}
