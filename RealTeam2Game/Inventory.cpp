/*#include "Inventory.h"
#include <iostream>

void Inventory::showInventory() const {
    if (items.empty()) {
        std::cout << "Your inventory is empty." << std::endl;
    } else {
        std::cout << "Inventory:" << std::endl;
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << ": " << item.getDescription() << std::endl;
        }
    }
}

bool Inventory::useItem(const std::string& itemName) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->getName() == itemName) {
            std::cout << "Using item: " << it->getName() << std::endl;
            items.erase(it);  // Remove the item after use
            return true;
        }
    }
    std::cout << "Item not found." << std::endl;
    return false;
}
*/