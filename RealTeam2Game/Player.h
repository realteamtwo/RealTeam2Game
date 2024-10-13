#include <string>
#include <vector>
#include "Item.h"
#include "Room.h"

#ifndef PLAYER
#define PLAYER
class Player {
public:
	//CONSTRUCTORS

	//Constructor for setting location; leaves the inventory empty
	//Doesn't exist yet; Room needs a default constructor
	//Player(Room);


	//MUTATORS
	
	//Sets the player's location to a new room
	void setRoom(Room);
	//Adds a new item to the inventory
	void addItem(Item);
	//Removes all items matching the given name from the inventory
	void removeItem(string);


	//ACCESSORS

	//Gets the player's location
	Room getRoom();
	//Gets the list of items, as a vector
	vector<Item> getItems();
private:
	Room location;
	vector<Item> items;
};
#endif
