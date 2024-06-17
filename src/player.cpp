// player.cpp
#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name, int health, int mana, int attackPower)
    : Character(name, health, mana, attackPower), currentLocation(Location("Magnolia Town", {"Goblin", "Green Slime"})),
      experience(0), level(1) {}

void Player::addItem(const std::string& item) {
    inventory.push_back(item);
    std::cout << item << " added to inventory." << std::endl;
}

void Player::displayInventory() const {
    std::cout << "===================================" << std::endl;
    std::cout << "========= " << name << "'s Inventory ========" << std::endl;
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

void Player::setLocation(const Location& location) {
    currentLocation = location;
}

Location Player::getLocation() const {
    return currentLocation;
}

void Player::gainExperience(int xp) {
    experience += xp;
    std::cout << name << " gained " << xp << " experience points." << std::endl;
    while (experience >= calculateExperienceForNextLevel()) {
        levelUp();
    }
}

int Player::getExperience() const {
    return experience;
}

int Player::getLevel() const {
    return level;
}

void Player::levelUp() {
    experience -= calculateExperienceForNextLevel();
    level++;
    health += 10; // Increase health upon leveling up
    mana += 10;   // Increase mana upon leveling up
    attackPower += 2; // Increase attack power upon leveling up
    std::cout << name << " leveled up! Now at level " << level << "." << std::endl;
    std::cout << "Stats increased: Health, Mana, Attack Power." << std::endl;
}

int Player::calculateExperienceForNextLevel() const {
    return level * 100; // Example formula: next level requires current level * 100 XP
}
