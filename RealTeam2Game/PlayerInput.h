#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <string>
#include "Item.h" 
#include "StopWatch.h"
#include "Level2.h"
#include "Player.h"
using namespace std;

class PlayerInput
{
public:
	PlayerInput(); // empty constructor

	void movePlayer(string direction);
	void itemInteraction(string command, StopWatch GameTime);
	

	void descend(Player &);

	bool hasMatch() const;
	bool hasTorch() const;
	bool riddleSolved() const;
	bool hasKey() const;
	bool hasRock() const;

	bool checkWin() const; 
	void printLevelTime() const;
	

private:

	string currentDirection;

    bool matchFound;
	bool torchFound;
	bool riddleVisible;
	bool riddleIsSolved;
	bool drawerUnlocked;
	bool keyFound;
	bool doorUnlocked;
	bool rockFound;
	
	

	Item match;
	Item torch;
	Item key;
	Item rock;
	Item fireextinguisher;
	Item matchstick;
	
};



#endif
