#include "character.h"
#include <iostream>

Character::Character(const std::string& name, int health, int mana, int attackPower)
    : name(name), health(health), mana(mana), attackPower(attackPower) {}

void Character::attack(Character& target) {
    target.health -= attackPower;
    std::cout << name << " attacks " << target.name << " for " << attackPower << " damage." << std::endl;
}

void Character::display() const {
    std::cout << name << " - Health: " << health << ", Mana: " << mana << ", Attack Power: " << attackPower << std::endl;
}

bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {
    return name;
}
