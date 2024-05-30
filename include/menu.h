// Menu.h
#ifndef MENU_H
#define MENU_H

#include "player.h"
#include "enemy.h"

class Menu {
public:
    Menu(Player& player, Enemy& enemy);
    void displayMenu();
    void startBattle();
    void viewStats();

private:
    Player& player;
    Enemy& enemy;
};

#endif // MENU_H
