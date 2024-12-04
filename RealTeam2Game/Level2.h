#ifndef LEVEL2
#define LEVEL2

#include <string>
#include "StopWatch.h"

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
	void displayDescription(Player &p);

	//Calls the appropriate function for interacting with the player's current room
	void interact(Player &p, std::string);

	//For tracking the completion of each side puzzle
	bool fireSolved = false;
	bool waterSolved = false;
	bool earthSolved = false;
	bool airSolved = false;

	bool checkWin(Player& p) const;

	void resetStopwatch();


private:
	//Center room function, takes the player's current input
	void runCenterRoom(Player &p, std::string);

	//down room function?
	void runDownRoom(Player &p, std::string);

	void runRightRoom(Player &p, std::string);
	bool fireextinguisherFound;
	bool matchstickFound;
	bool rightRoomEntered;
	bool sharpRockFound;
	bool jarOfEarthwormsFound;
	bool glassBroken;

	void runUpRoom(Player& p, std::string);

	void runLeftRoom(Player& p, std::string);
	
	StopWatch L2Time;
};

#endif
