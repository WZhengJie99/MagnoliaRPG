#include "player.h"
#include "menu.h"
#include <iostream>

int main() {
    Player player("Hero", 100, 100, 20);
    Menu menu(player);
    menu.displayMenu();
    return 0;
}
