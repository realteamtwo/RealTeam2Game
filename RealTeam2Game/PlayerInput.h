
#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include <string>
#include "Item.h"
using namespace std;

class PlayerInput
{
public:
	PlayerInput(); // empty constructor

	void movePlayer(string direction);
	void itemInteraction(string command);
	


	bool hasTorch() const;
	bool riddleSolved() const;
	bool hasKey() const;

private:

	string currentDirection;
	bool torchFound;
	bool riddleVisible;
	bool riddleIsSolved;
	bool drawerUnlocked;
	bool keyFound;
	bool doorUnlocked;
	


	Item torch;
	Item key;

};



#endif
