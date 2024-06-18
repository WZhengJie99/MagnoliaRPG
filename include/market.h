//market.h
#ifndef MARKET_H
#define MARKET_H

#include "player.h"
#include <string>
#include <unordered_map>

class Market {
public:
    Market();

    void displayItems() const;
    void buyItem(Player& player, const std::string& item);
    void sellItem(Player& player, const std::string& item);

private:
    std::unordered_map<std::string, int> itemsForSale; // Define itemsForSale
};

#endif // MARKET_H
