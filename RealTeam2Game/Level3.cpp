//cpp for Level 3 (the potion room) will be where location descriptions snd interactions for the player will be
#include "Level3.h"
#include "Player.h"



//when player enters a room they get a description so they know what's up. The player is also informed of how to move
void Level3::displayDescription(Player& p) {
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

//for interaction based on player's input as seen in RealTeam2Game.cpp
//takes input string
//each room has interactions specific for the room so it matters which room they are in
void Level3::interact(Player& p, std::string input) {
	//based on player's current location does specific run function
	switch (p.getLocation()) {
	//starting
	case Location::CENTER_ROOM:
		Level3::runCenterRoom(p, input);
		break;

	case Location::DOWN_ROOM:
		Level3::runDownRoom(p, input);
		break;

	case Location::RIGHT_ROOM:
		Level3::runRightRoom(p, input);
		break;

	case Location::LEFT_ROOM:
		Level3::runLeftRoom(p, input);
		break;

	case Location::UP_ROOM:
		Level3::runUpRoom(p, input);
		break;
	}
}

void Level3::runCenterRoom(Player& p, std::string input) {
	if (input == "down") {
		cout << " you go down " << endl;
		//update location to DOWN_ROOM
		p.setLocation(Level2::Location::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation(Level2::Location::UP_ROOM);
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " you go left" << endl;
		p.setLocation(Level2::Location::LEFT_ROOM);
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " you go right" << endl;
		p.setLocation(Level2::Location::RIGHT_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "leave") {
		cout << " You're In Center Room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
		//update location to RIGHT_ROOM
	}
	//need unlocking here

}

void Level3::runDownRoom(Player& p, std::string input) {

}
void Level3::runRightRoom(Player& p, std::string input) {

}
void Level3::runUpRoom(Player& p, std::string input) {

}
void Level3::runLeftRoom(Player& p, std::string input) {

}