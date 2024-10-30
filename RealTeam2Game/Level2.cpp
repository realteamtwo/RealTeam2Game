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
	// 
	//for the air room
	case Location::DOWN_ROOM:
		cout << "You move down to a room with writing on the walls. A breeze passes by you"<< endl;
		break;
		//for fire room
	case Location::RIGHT_ROOM:
		cout << "You move right to a room with light gleaming and intense heat suffocating you" << endl;
		break;
		//for water room
	case Location::LEFT_ROOM:
		cout << "You move left to a room with the smell of the ocean and beautiful sea creatures around in a tank" << endl;
		break;
		//for earth room
	case Location::UP_ROOM:
		cout << "The room you are within has rock walls and a dirt floor, and you are overwhelmed by a sandstorm engulfing the room" << endl;
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

		case Location::LEFT_ROOM:
			Level2::runLeftRoom(p, input);
			break;

		case Location::UP_ROOM:
			Level2::runUpRoom(p, input);
			break;
	}
}

void Level2::runCenterRoom(Player &p, std::string input) {
	
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
		cout << " Your In Center Room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
		//update location to RIGHT_ROOM
	}
}

void Level2::runDownRoom(Player &p, std::string input) {
	cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
	
	if (input == "down") {
		cout << "What travels in the daylight but casts no shadow? What can you feel but you cannot see?" << endl;
	}

	if (input == "left") {
		cout << "The wall is decorated with swirls" << endl;
	}

	if (input == "right") {
		cout << "There are many pinwheels huddled together here " << endl;
	}

	if (input == "up") {
		cout << "The doorway you came from has many tassels and cloth flowing in the breeze" << endl;
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
}

void Level2::runRightRoom(Player& p, std::string input) {
	cout << "Right Room Interaction" << endl;

	if (input == "down") {
		cout << "Do Your Work 4 down:)" << endl;
	}

	if (input == "left") {
		cout << "Do Your Work 4 left :)" << endl;
	}

	if (input == "right") {
		cout << "Do Your Work 4 right :)" << endl;
	}

	if (input == "up") {
		cout << "Do Your Work 4 up :)" << endl;
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
}

void Level2::runLeftRoom(Player& p, std::string input) {
	cout << "Left Room Interaction" << endl;

	if (input == "down") {
		cout << "Do Your Work 4 down:)" << endl;
	}

	if (input == "left") {
		cout << "Do Your Work 4 left :)" << endl;
	}

	if (input == "right") {
		cout << "Do Your Work 4 right :)" << endl;
	}

	if (input == "up") {
		cout << "Do Your Work 4 up :)" << endl;
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
		}
	/*
	cout << "Water Room" << endl;
	if (input == "down") {
		cout << "The back wall is rough and rocky. There appears to be nothing of use on this side of the room." << endl;
	}
	else if (input == "up") {
		cout << "The front wall has text on it.\nI'm the third rock from the sun, with one moon as my companion\nIf you don't take care of me, who knows what'll happen" << endl;
		cout << "I have oceans so deep and moutains so high\nI'm your home. What am I?" << endl;
	}
	else if (input == "left") {
		cout << "The left wall is covered with large, spiky rocks. A chunk of one seems to have broken off onto the floor." << endl;
	}
	else if (input == "right") {
		cout << "The right wall contains a large container protected by thick glass. Maybe something can break it?" << endl;
	}*/
}

void Level2::runUpRoom(Player& p, std::string input) {
	cout << "EARTH ROOM" << endl;
	if (input == "down") {
		cout << "The back wall is rough and rocky. There appears to be nothing of use on this side of the room." << endl;
	}
	else if (input == "up") {
		cout << "The front wall has text on it.\nI'm the third rock from the sun, with one moon as my companion\nIf you don't take care of me, who knows what'll happen" << endl;
		cout << "I have oceans so deep and moutains so high\nI'm your home. What am I?" << endl;
	}
	else if (input == "left") {
		cout << "The left wall is covered with large, spiky rocks. A chunk of one seems to have broken off onto the floor." << endl;
	}
	else if (input == "right") {
		cout << "The right wall contains a large container protected by thick glass. Maybe something can break it?" << endl;
	}

	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
}