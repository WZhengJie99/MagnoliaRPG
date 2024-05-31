#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name, int health, int mana, int attackPower)
    : Character(name, health, mana, attackPower) {}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << item << " added to inventory." << std::endl;
}

void Player::displayInventory() const {
    std::cout << "===== " << name << "'s Inventory =====" << std::endl;
    for (const auto& item : inventory) {
        std::cout << "- " << item << std::endl;
    }
}

void Player::useItem(const std::string& item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        if (item == "Health Potion") {
            health += 20; // Increase health by 20, for example
            std::cout << "Used Health Potion. Health is now " << health << "." << std::endl;
        } else if (item == "Mana Potion") {
            mana += 20; // Increase mana by 20, for example
            std::cout << "Used Mana Potion. Mana is now " << mana << "." << std::endl;
        }
        inventory.erase(it); // Remove the item from the inventory
    } else {
        std::cout << "Item not found in inventory." << std::endl;
    }
}

const std::vector<std::string>& Player::getInventory() const {
    return inventory;
}

