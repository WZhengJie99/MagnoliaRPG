// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "location.h"
#include <vector>
#include <string>

class Player : public Character {
public:
    Player(const std::string& name, int health, int mana, int attackPower);
    void addItem(const std::string& item);
    void displayInventory() const;
    void useItem(const std::string& item);
    const std::vector<std::string>& getInventory() const;
    void setLocation(const Location& location);
    Location getLocation() const;
private:
    std::vector<std::string> inventory;
    Location currentLocation;
};

#endif // PLAYER_H