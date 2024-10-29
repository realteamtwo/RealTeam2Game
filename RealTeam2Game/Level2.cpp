#include "Level2.h"
#include "Player.h"

Level2::Level2() {
	//do nothing
}

void Level2::displayDescription(Player p) {
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
	}
}

void Level2::interact(Player p, std::string input) {
	switch (p.getLocation()) {
		case Location::CENTER_ROOM:
		Level2::runCenterRoom(input);
		break;
		
		case Location::DOWN_ROOM:
		Level2::runDownRoom(input);
		break;
	}
}

void Level2::runCenterRoom(std::string input) {
	cout << "Center Room Interaction (Placeholder)" << endl;
}

void Level2::runDownRoom(std::string input) {
	cout << "Down Room Interaction (Placeholder)" << endl;
}