// Menu.cpp
#include "menu.h"
#include <iostream>

Menu::Menu(Player& player, Enemy& enemy)
    : player(player), enemy(enemy) {}

void Menu::displayMenu() {
    int choice;
    do {
        std::cout << "==== RPG Menu ====" << std::endl;
        std::cout << "1. View Stats" << std::endl;
        std::cout << "2. Start Battle" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewStats();
                break;
            case 2:
                startBattle();
                break;
            case 3:
                std::cout << "Exiting the game. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 3);
}

void Menu::startBattle() {
    std::cout << "Battle Start!" << std::endl;

    while (player.isAlive() && enemy.isAlive()) {
        player.attack(enemy);
        if (enemy.isAlive()) {
            enemy.attack(player);
        }
    }

    if (player.isAlive()) {
        std::cout << player.getName() << " has defeated " << enemy.getName() << "!" << std::endl;
    } else {
        std::cout << player.getName() << " has been defeated by " << enemy.getName() << "..." << std::endl;
    }

    std::cout << "Returning to menu..." << std::endl;
}

void Menu::viewStats() {
    std::cout << "==== Player Stats ====" << std::endl;
    player.display();
}
