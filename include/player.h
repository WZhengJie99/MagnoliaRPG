// player.h
#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"
#include "location.h"
#include <string>
#include <vector>

class Player : public Character {
public:
    Player(const std::string& name, int health, int mana, int attackPower);

    void addItem(const std::string& item);
    void removeItem(const std::string& item);
    void useItem(const std::string& item); // Add this method declaration
    void displayInventory() const;
    const std::vector<std::string>& getInventory() const;

    void setLocation(const Location& location);
    Location getLocation() const;

    void gainExperience(int xp);
    void setCoins(int coins);
    int getCoins() const;

private:
    std::vector<std::string> inventory;
    Location currentLocation;
    int experience = 0;
    int coins = 0;
};

#endif // PLAYER_H
