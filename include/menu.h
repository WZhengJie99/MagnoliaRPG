// menu.h
#ifndef MENU_H
#define MENU_H

#include "player.h"
#include "enemy.h"

class Menu {
public:
    Menu(Player& player);
    void displayMenu();
private:
    void viewStats();
    void viewInventory();
    void startBattle();
    void useItem();
    void travel();  // Add the declaration here
    void createEnemy();
    void addItemToPlayer(const std::string& item);

    Player& player;
    Enemy* enemy;
};

#endif // MENU_H
