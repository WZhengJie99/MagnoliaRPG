#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public Character {
public:
    Enemy(const std::string& name, int health, int attackPower);
};

#endif // ENEMY_H
