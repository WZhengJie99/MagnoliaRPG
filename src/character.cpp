#include "character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int attackPower)
    : name(name), health(health), attackPower(attackPower) {}

void Character::attack(Character& target) {
    target.health -= attackPower;
    std::cout << name << " attacks " << target.name << " for " << attackPower << " damage." << std::endl;
}

void Character::display() const {
    std::cout << name << " - Health: " << health << ", Attack Power: " << attackPower << std::endl;
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {  // Implement this method
    return name;
}
