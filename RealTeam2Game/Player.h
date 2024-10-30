#ifndef PLAYER
#define PLAYER

#include <string>
#include <vector>
#include "Item.h"
#include "Level2.h"
#include "Room.h"

class Player {
private:
	Level2::Location location;
	vector<Item> items;
	int level;
public:
	//CONSTRUCTORS

	//Default constructor; sets level to 1 and makes an empty inventory
	Player();


	//MUTATORS
	
	//Sets the player's location to a new room
	void setLocation(Level2::Location);
	//Adds a new item to the inventory
	void addItem(Item);
	//Removes all items matching the given name from the inventory
	void removeItem(string);
	//Sets the player's current level
	void setLevel(int);
	


	//ACCESSORS

	//Gets the player's location
	Level2::Location getLocation();
	//Gets the list of items, as a vector
	vector<Item> getItems();
	//Gets the player's current level
	int getLevel();
};
#endif
