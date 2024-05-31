#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
public:
    Character(const std::string& name, int health, int mana, int attackPower);
    void attack(Character& target);
    void display() const;
    bool isAlive() const;
    std::string getName() const;

protected:
    std::string name;
    int health;
    int mana;
    int attackPower;
};

#endif

