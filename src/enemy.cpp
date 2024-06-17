// enemy.cpp
#include "enemy.h"

Enemy::Enemy(const std::string& name, int health, int mana, int attackPower, int experiencePoints, const std::string& itemDrop)
    : Character(name, health, mana, attackPower), experiencePoints(experiencePoints), itemDrop(itemDrop) {}

int Enemy::getExperiencePoints() const {
    return experiencePoints;
}

std::string Enemy::getItemDrop() const {
    return itemDrop;
}
