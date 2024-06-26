// menu.cpp
#include "menu.h"
#include "location.h"
#include "market.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

Menu::Menu(Player& player) : player(player), enemy(nullptr) {
    std::srand(std::time(0)); // Seed the random number generator
}

void Menu::displayMenu() {
    int choice;
    do {
        std::cout << "===================================" << std::endl;
        std::cout << "============ RPG Menu =============" << std::endl;
        std::cout << "Location: " << player.getLocation().getName() << std::endl;
        std::cout << "1. View Stats" << std::endl;
        std::cout << "2. View Inventory" << std::endl;
        std::cout << "3. Go to Market" << std::endl;
        std::cout << "4. Start Battle" << std::endl;
        std::cout << "5. Use Item" << std::endl;
        std::cout << "6. Travel" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        // Input validation
        while (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 6: ";
            std::cin.clear(); // clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        }

        switch (choice) {
            case 1:
                viewStats();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                openMarket();
                break;
            case 4:
                startBattle();
                break;
            case 5:
                useItem();
                break;
            case 6:
                travel();
                break;
            case 7:
                std::cout << "Exiting the game. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 7);
}

void Menu::viewStats() {
    std::cout << "===================================" << std::endl;
    std::cout << "=========== Player Stats ==========" << std::endl;
    player.display();
}

void Menu::viewInventory() {
    player.displayInventory();
}

void Menu::startBattle() {
    createEnemy();
    std::cout << "===================================" << std::endl;
    std::cout << "=========== Battle Start! =========" << std::endl;

    while (player.isAlive() && enemy->isAlive()) {
        player.attack(*enemy);
        if (enemy->isAlive()) {
            enemy->attack(player);
        }
    }

    if (player.isAlive()) {
        std::cout << player.getName() << " has defeated " << enemy->getName() << "!" << std::endl;
        int xp = enemy->getExperiencePoints();
        player.gainExperience(xp);
        std::string itemDrop = enemy->getItemDrop();
        addItemToPlayer(itemDrop);
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

    std::cout << "===================================" << std::endl;
    std::cout << "====== Choose an item to use: =====" << std::endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << (i + 1) << ". " << inventory[i] << std::endl;
    }

    int choice;
    std::cout << "Enter your choice: ";
    while (!(std::cin >> choice)) {
        std::cout << "Invalid input. Please enter a valid item number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (choice > 0 && choice <= static_cast<int>(inventory.size())) {
        player.useItem(inventory[choice - 1]);
    } else {
        std::cout << "Invalid choice. No item used." << std::endl;
    }
}

void Menu::travel() {
    std::cout << "===================================" << std::endl;
    std::cout << "Choose a new location to travel to:" << std::endl;
    std::cout << "1. Magnolia Town" << std::endl;
    std::cout << "2. Dark Forest" << std::endl;
    std::cout << "3. Crystal Cave" << std::endl;

    int choice;
    std::cout << "Enter your choice: ";
    while (!(std::cin >> choice)) {
        std::cout << "Invalid input. Please enter a number between 1 and 3: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    switch (choice) {
        case 1:
            player.setLocation(Location("Magnolia Town", {"Goblin", "Green Slime"}));
            break;
        case 2:
            player.setLocation(Location("Dark Forest", {"Werewolf", "Vampire"}));
            break;
        case 3:
            player.setLocation(Location("Crystal Cave", {"Crystal Golem", "Cave Bat"}));
            break;
        default:
            std::cout << "Invalid choice. Staying in current location." << std::endl;
            break;
    }
}

void Menu::openMarket() {
    Market market;
    while (true) {
        market.displayItems();
        std::cout << "===================================" << std::endl;
        std::cout << "1. Buy Item" << std::endl;
        std::cout << "2. Sell Item" << std::endl;
        std::cout << "3. Return to Main Menu" << std::endl;
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        if (choice == 3) {
            break;
        }

        std::string item;
        switch (choice) {
            case 1:
                std::cout << "Enter item to buy: ";
                std::cin >> item;
                market.buyItem(player, item);
                break;
            case 2:
                std::cout << "Enter item to sell: ";
                std::cin >> item;
                market.sellItem(player, item);
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void Menu::createEnemy() {
    const std::vector<std::string>& monsters = player.getLocation().getMonsters();
    int randomIndex = std::rand() % monsters.size();
    std::string enemyName = monsters[randomIndex];

    // name, health, mana, attackPower, experiencePoints, itemDrop
    if (enemyName == "Goblin") {
        enemy = new Enemy("Goblin", 50, 0, 10, 50, "Health Potion");
    } else if (enemyName == "Green Slime") {
        enemy = new Enemy("Green Slime", 20, 0, 5, 20, "Mana Potion");
    } else if (enemyName == "Werewolf") {
        enemy = new Enemy("Werewolf", 80, 0, 15, 100, "Health Potion");
    } else if (enemyName == "Vampire") {
        enemy = new Enemy("Vampire", 70, 0, 20, 120, "Health Potion");
    } else if (enemyName == "Crystal Golem") {
        enemy = new Enemy("Crystal Golem", 100, 0, 25, 150, "Mana Potion");
    } else if (enemyName == "Cave Bat") {
        enemy = new Enemy("Cave Bat", 30, 0, 10, 40, "Health Potion");
    }
}

