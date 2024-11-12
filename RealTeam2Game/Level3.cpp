//cpp for Level 3 (the potion room) will be where location descriptions snd interactions for the player will be
#include "Level3.h"
#include "Player.h"


Level3::Level3() {}


//when player enters a room they get a description so they know what's up. The player is also informed of how to move
void Level3::displayDescription(Player& p) {
	switch (p.getLocation3()) {

	//first case and player starts here, where trapdoor is located so if else statement should occur to check locked or unlocked
	case Location3::CENTER_ROOM:
		
		//current description perhaps some flair for a potion room:)
		//also will be in the else once we figure out how the door unlocks in this room
		cout << "You are in a central area with another locked trapdoor." << endl;
		cout << "Four hallways extend from this room to other areas." << endl;
		break;

		//put which room
	case Location3::DOWN_ROOM:
		cout << "A room full of shelves and boxes of unknown contents line the walls. Paper and clutter stretches out before you. Type look to look around" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		// put which room it is
	case Location3::RIGHT_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;

		break;
		//put which
	case Location3::LEFT_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		//put which room
	case Location3::UP_ROOM:
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
	switch (p.getLocation3()) {
	//starting
	case Location3::CENTER_ROOM:
		Level3::runCenterRoom(p, input);
		break;

	case Location3::DOWN_ROOM:
		Level3::runDownRoom(p, input);
		break;

	case Location3::RIGHT_ROOM:
		Level3::runRightRoom(p, input);
		break;

	case Location3::LEFT_ROOM:
		Level3::runLeftRoom(p, input);
		break;

	case Location3::UP_ROOM:
		Level3::runUpRoom(p, input);
		break;
	}
}

void Level3::runCenterRoom(Player& p, std::string input) {
	if (input == "down") {
		cout << " you go down " << endl;
		//update location to DOWN_ROOM
		p.setLocation3(Level3::Location3::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation3(Level3::Location3::UP_ROOM);
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " you go left" << endl;
		p.setLocation3(Level3::Location3::LEFT_ROOM);
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " you go right" << endl;
		p.setLocation3(Level3::Location3::RIGHT_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "leave") {
		cout << " You're In Center Room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "ascend")
	{
		cout << "You went back to the previous room." << endl;
		p.setLevel(2);
		//Set level back to level 2
	}
	//need unlocking here
	// Add Stop Watch Code for Level 3
}

void Level3::runDownRoom(Player& p, std::string input) {
	//prompt
	cout << "Perhaps there is something useful here?" << endl;
	//based on input of player different things can happen (for information check player files and main)
	if (input == "look") {
		cout << "Some of the boxes to your left and right stand out. " << endl;
	}
	//theoretically we would want this to be pressed after look but no reason they shouldn't be able to
	else if (input == "left") {
		cout << "There is an open chest. Inside there is what looks like the fossilized remains of a snake, and a vile of liquid" << endl;

	}
	else if (input == "right") {
		cout << "Amongst several piles of paper is a metalic cylinder. A warning label reads 'Do Not Open: Magic Powder'" << endl;

	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
	}
		
}
void Level3::runRightRoom(Player& p, std::string input) {

}
void Level3::runUpRoom(Player& p, std::string input) {

}
void Level3::runLeftRoom(Player& p, std::string input) {

}