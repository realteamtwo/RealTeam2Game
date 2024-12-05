#ifndef LEVEL4
#define LEVEL4

#include <string>
#include "StopWatch.h"

//Header file for Level 4 (The Alchemist's Room), structured the same as Level 2 and 3

class Player;

class Level4
{
public:
	//Enum, one entry for each location
	enum Location4 { CENTER_ROOM, DOWN_ROOM, UP_ROOM, LEFT_ROOM, RIGHT_ROOM };

	//Constructor
	Level4();

	//Checks the player's current room and prints the description for it
	void displayDescription(Player& p);

	//Calls the appropriate function for interacting with the player's current room
	void interact(Player& p, std::string);

	//Checks if a riddle has been solved yet
	bool getRiddleSolved(int riddleNumber);
private:
	//Center room function, takes the player's current input, runs if in center room and is where player first goes
	void runCenterRoom(Player& p, std::string);

	//For running down room takes player input, runs if player inputs down in center room
	void runDownRoom(Player& p, std::string);

	//For running right room takes player input, runs if player inputs right in center room
	void runRightRoom(Player& p, std::string);

	//For running up room takes player input, runs if player inputs up in center room
	void runUpRoom(Player& p, std::string);

	//For running left room takes player input, runs if player inputs left in center room
	void runLeftRoom(Player& p, std::string);

	//Initialize riddle check variables
	bool riddleOneSolved;
	bool riddleTwoSolved;
	bool riddleThreeSolved;

	StopWatch L4Time;
};

#endif