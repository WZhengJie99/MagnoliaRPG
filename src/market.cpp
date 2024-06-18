//market.cpp
#include "market.h"
#include <algorithm>
#include <iostream>

Market::Market() {
    // Initialize the market with items and their prices
    itemsForSale = {
        {"Health Potion", 50},
        {"Mana Potion", 50}
    };
}

void Market::displayItems() const {
    std::cout << "Items available for purchase:" << std::endl;
    for (const auto& item : itemsForSale) {
        std::cout << "- " << item.first << ": " << item.second << " coins" << std::endl;
    }
}

void Market::buyItem(Player& player, const std::string& item) {
    auto it = itemsForSale.find(item);
    if (it != itemsForSale.end()) {
        int price = it->second;
        if (player.getCoins() >= price) {
            player.addItem(item);
            player.setCoins(player.getCoins() - price);
            std::cout << "Purchased " << item << " for " << price << " coins." << std::endl;
        } else {
            std::cout << "Not enough coins to buy " << item << "." << std::endl;
        }
    } else {
        std::cout << "Item not available in market." << std::endl;
    }
}

void Market::sellItem(Player& player, const std::string& item) {
    auto& inventory = player.getInventory();  // Get a non-const reference to the player's inventory
    auto itemIt = std::find(inventory.begin(), inventory.end(), item);
    if (itemIt != inventory.end()) {
        int sellPrice = itemsForSale[item] / 2; // Sell for half the purchase price
        player.setCoins(player.getCoins() + sellPrice);
        player.removeItem(item); // Remove the item from the player's inventory
        std::cout << "Sold " << item << " for " << sellPrice << " coins." << std::endl;
    } else {
        std::cout << "Item not found in inventory." << std::endl;
    }
}
