#include "Level2.h"
#include "Player.h"

Level2::Level2() {
	//do nothing
}

void Level2::displayDescription(Player &p) {
	switch (p.getLocation()) {
	case Location::CENTER_ROOM:
		cout << "You are in a central area with another locked trapdoor." << endl;
		cout << "Four hallways extend from this room to other areas." << endl;
		break;
	////is this how you want the format of the code? -Nicole
	//for the air room
	case Location::DOWN_ROOM:
		cout << "You move down to a room with writing on the walls"<< endl;
		break;
		//for fire room
	case Location::RIGHT_ROOM:
		cout << "You move right to a room with light gleaming and intense heat suffocating you" << endl;
		break;
	}
}

void Level2::interact(Player &p, std::string input) {
	switch (p.getLocation()) {
		case Location::CENTER_ROOM:
		Level2::runCenterRoom(p, input);
		break;
		
		case Location::DOWN_ROOM:
		Level2::runDownRoom(p, input);
		break;

		case Location::RIGHT_ROOM:
			Level2::runRightRoom(p, input);
		break;
	}
}

void Level2::runCenterRoom(Player &p, std::string input) {
	cout << "Center Room Interaction (Placeholder)" << endl;
	if (input == "down") {
		cout << " you go down " << endl;
		p.setLocation(Level2::Location::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << " you go up" << endl;
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " you go left" << endl;
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " you go right" << endl;
		//update location to RIGHT_ROOM
	}
}

void Level2::runDownRoom(Player &p, std::string input) {
	cout << "Down Room Interaction (Placeholder)" << endl;
}

void Level2::runRightRoom(Player& p, std::string input) {
	cout << "Right Room Interaction" << endl;
}