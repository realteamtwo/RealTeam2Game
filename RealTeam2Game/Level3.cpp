//cpp for Level 3 (the potion room) will be where location descriptions snd interactions for the player will be
#include "Level3.h"
#include "Player.h"

using namespace std;

//when player enters a room they get a description so they know what's up. The player is also informed of how to move
void Level2::displayDescription(Player& p) {
	switch (p.getLocation()) {

	//first case and player starts here, where trapdoor is located so if else statement should occur to check locked or unlocked
	case Location::CENTER_ROOM:
		
		//current description perhaps some flair for a potion room:)
		//also will be in the else once we figure out how the door unlocks in this room
		cout << "You are in a central area with another locked trapdoor." << endl;
		cout << "Four hallways extend from this room to other areas." << endl;
		break;

		//put which room
	case Location::DOWN_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		// put which room it is
	case Location::RIGHT_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;

		break;
		//put which
	case Location::LEFT_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		//put which room
	case Location::UP_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
	}
}
