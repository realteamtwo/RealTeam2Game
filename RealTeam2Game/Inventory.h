/*#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory {
public:
    Inventory() {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    void showInventory() const {
        if (items.empty()) {
            std::cout << "Your inventory is empty." << std::endl;
        }
        else {
            std::cout << "Inventory:" << std::endl;
            for (const auto& item : items) {
                std::cout << "- " << item.getName() << ": " << item.getDescription() << std::endl;
            }
        }
    }

    bool useItem(const std::string& itemName) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->getName() == itemName) {
                // In a real game, use the item in some way
                std::cout << "Using item: " << it->getName() << std::endl;
                items.erase(it);  // Remove the item from inventory after use
                return true;
            }
        }
        std::cout << "Item not found." << std::endl;
        return false;
    }

private:
    std::vector<Item> items;
};

#endif
*/

