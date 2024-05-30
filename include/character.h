#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character {
protected:
    std::string name;
    int health;
    int attackPower;

public:
    Character(const std::string& name, int health, int attackPower);

    void attack(Character& target);
    void display() const;

    bool isAlive() const;
    
    std::string getName() const;
};

#endif // CHARACTER_H
