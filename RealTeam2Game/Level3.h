#ifndef LEVEL3
#define LEVEL3

#include <string>
#include "StopWatch.h"

//Header file for level 3 (The Potion Room) much like level 2. Sets up level3 class and has player class


class Player;

//general class for level 3 contains functions for location descriptions, player interaction in locations, and running the correct location
class Level3 {
public:

	//Enum, one entry for each location
	//let me know if you guys would like to rename these or if there will be more or if the shape is different
	enum Location3 { CENTER_ROOM, DOWN_ROOM, UP_ROOM, LEFT_ROOM, RIGHT_ROOM };

	//Constructor
	Level3();
	// display the description of the locked door.
	void displayDoorDescription();
	//Checks the player's current room and prints the description for it
	void displayDescription(Player& p);

	//Calls the appropriate function for interacting with the player's current room
	void interact(Player& p, std::string);
private:

	//Center room function, takes the player's current input, runs if in center room and is where player first goes
	void runCenterRoom(Player& p, std::string);

	//for running down room takes player input, runs if player inputs down in center room
	void runDownRoom(Player& p, std::string);

	//for running right room takes player input, runs if player inputs right in center room
	void runRightRoom(Player& p, std::string);

	//for running up room takes player input, runs if player inputs up in center room
	void runUpRoom(Player& p, std::string);

	//for running left room takes player input, runs if player inputs left in center room
	void runLeftRoom(Player& p, std::string);

	StopWatch L3Time;
};




#endif
