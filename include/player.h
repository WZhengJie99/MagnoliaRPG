#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include <vector>
#include <string>

class Player : public Character {
private:
    std::vector<std::string> inventory;

public:
    Player(const std::string& name, int health, int attackPower);

    void addItem(const std::string& item);
    void displayInventory() const;
};

#endif // PLAYER_H
