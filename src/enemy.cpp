// enemy.cpp
#include "enemy.h"

Enemy::Enemy(const std::string& name, int health, int mana, int attackPower)
    : Character(name, health, mana, attackPower) {}
