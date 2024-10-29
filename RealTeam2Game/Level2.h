#ifndef LEVEL2
#define LEVEL2

#include <string>

class Player;

class Level2 {
public:
	//Enum, one entry for each location
	//See discord notes for how to add a new location
	enum Location { CENTER_ROOM, DOWN_ROOM, UP_ROOM, LEFT_ROOM, RIGHT_ROOM };
	//hoping I am doing this right and I added all rooms so people could get idea - nicole
	

	//Constructor
	Level2();

	//Checks the player's current room and prints the description for it
	void displayDescription(Player p);

	//Calls the appropriate function for interacting with the player's current room
	void interact(Player p, std::string);

private:
	//Center room function, takes the player's current input
	void runCenterRoom(std::string);

	//down room function?
	void runDownRoom(std::string);
};

#endif
