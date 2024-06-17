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
    void displayInventory() const;
    void useItem(const std::string& item);
    const std::vector<std::string>& getInventory() const;

    void setLocation(const Location& location);
    Location getLocation() const;

    // New methods for experience and leveling up
    void gainExperience(int xp);
    int getExperience() const;
    int getLevel() const;
    void levelUp();

private:
    std::vector<std::string> inventory;
    Location currentLocation;

    // New attributes for experience and level
    int experience;
    int level;

    // Helper method to calculate the experience required for the next level
    int calculateExperienceForNextLevel() const;
};

#endif // PLAYER_H