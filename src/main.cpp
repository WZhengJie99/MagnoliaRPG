#include "player.h"
#include "enemy.h"
#include "menu.h"
#include <iostream>

int main() {
    Player player("Hero", 100, 20);
    Enemy enemy("Goblin", 50, 10);

    Menu menu(player, enemy);
    menu.displayMenu();

    return 0;
}