#include <string>
#include <vector>
#include "Player.h"

//Constructors
Player::Player() {
	level = 1;
	location = Level2::Location::CENTER_ROOM;
}


//Mutators
void Player::setLocation(Level2::Location l) {
	location = l;
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

void Player::setLevel(int l) {
	level = l;
}

void Player::setLocation3(Level3::Location3 l) {
	location3 = l;
}

//Accessors
Level2::Location Player::getLocation() {
	return location;
}

Level3::Location3 Player::getLocation3() {
	return location3;
}

vector<Item> Player::getItems() {
	return items;
}


int Player::getLevel() {
	return level;
}