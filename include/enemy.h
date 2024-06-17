#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"
#include <string>

class Enemy : public Character {
public:
    Enemy(const std::string& name, int health, int mana, int attackPower, int experiencePoints, const std::string& itemDrop);

    int getExperiencePoints() const;
    std::string getItemDrop() const;

private:
    int experiencePoints;
    std::string itemDrop;
};

#endif // ENEMY_H
