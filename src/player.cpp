#include "player.h"
#include <iostream>

Player::Player(const std::string& name, int health, int attackPower)
    : Character(name, health, attackPower) {}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << item << " added to inventory." << std::endl;
}

void Player::displayInventory() const {
    std::cout << name << "'s Inventory:" << std::endl;
    for (const auto& item : inventory) {
        std::cout << "- " << item << std::endl;
    }
}
