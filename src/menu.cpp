// Menu.cpp
#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Menu::Menu(Player& player) : player(player), enemy(nullptr) {
    std::srand(std::time(0)); // Seed the random number generator
}

void Menu::displayMenu() {
    int choice;
    do {
        std::cout << "========= RPG Menu =========" << std::endl;
        std::cout << "1. View Stats" << std::endl;
        std::cout << "2. View Inventory" << std::endl;
        std::cout << "3. Start Battle" << std::endl;
        std::cout << "4. Use Item" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                viewStats();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                startBattle();
                break;
            case 4:
                useItem();
                break;
            case 5:
                std::cout << "Exiting the game. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 5);
}

void Menu::viewStats() {
    std::cout << "======= Player Stats =======" << std::endl;
    player.display();
}

void Menu::viewInventory() {
    player.displayInventory();
}

void Menu::startBattle() {
    createEnemy();
    std::cout << "======= Battle Start! ======" << std::endl;

    while (player.isAlive() && enemy->isAlive()) {
        player.attack(*enemy);
        if (enemy->isAlive()) {
            enemy->attack(player);
        }
    }

    if (player.isAlive()) {
        std::cout << player.getName() << " has defeated " << enemy->getName() << "!" << std::endl;
        if (enemy->getName() == "Goblin") {
            addItemToPlayer("Health Potion");
        } else if (enemy->getName() == "Slime") {
            addItemToPlayer("Mana Potion");
        }
    } else {
        std::cout << player.getName() << " has been defeated by " << enemy->getName() << "..." << std::endl;
    }

    delete enemy; // Clean up the dynamically allocated enemy
    enemy = nullptr;

    std::cout << "Returning to menu..." << std::endl;
}

void Menu::addItemToPlayer(const std::string& item) {
    player.addItem(item);
}

void Menu::useItem() {
    const std::vector<std::string>& inventory = player.getInventory();
    if (inventory.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
        return;
    }

    std::cout << "== Choose an item to use: ==" << std::endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << (i + 1) << ". " << inventory[i] << std::endl;
    }

    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    if (choice > 0 && choice <= static_cast<int>(inventory.size())) {
        player.useItem(inventory[choice - 1]);
    } else {
        std::cout << "Invalid choice. No item used." << std::endl;
    }
}

void Menu::createEnemy() {
    // Randomly create an enemy
    int randomEnemy = std::rand() % 2;
    if (randomEnemy == 0) {
        enemy = new Enemy("Goblin", 50, 0, 10);
    } else if (randomEnemy == 1){
        enemy = new Enemy("Green Slime", 20, 0, 5);
    } else {
        enemy = new Enemy("Blue Slime", 20, 0, 5);
    }
}
