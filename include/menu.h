// Menu.h
#ifndef MENU_H
#define MENU_H

#include "player.h"
#include "enemy.h"

class Menu {
public:
    Menu(Player& player);
    void displayMenu();
    void viewStats();
    void viewInventory();
    void startBattle();
    void addItemToPlayer(const std::string& item);
    void useItem();

private:
    Player& player;
    Enemy* enemy;
    void createEnemy();
};

#endif
