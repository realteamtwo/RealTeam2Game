#include <string>
#include <vector>
#include "Player.h"

//Constructors
Player::Player(Room r) {
	location = r;
}

//Mutators
void Player::setRoom(Room r) {
	location = r;
}

void Player::addItem(Item i) {
	items.push_back(i);
}

void Player::removeItem(string name) {
	for (int i = items.size() - 1; i >= 0; i--) {
		if (items[i].getDisplayName() == name) {
			items.erase(items.begin() + i);
		}
	}
}

//Accessors
Room Player::getRoom() {
	return location;
}

vector<Item> Player::getItems() {
	return items;
}