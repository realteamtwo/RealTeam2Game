//cpp for Level 4 (The Alchemist's Room) will be where location descriptions snd interactions for the player will be
#include "Level4.h"
#include "Player.h"
#include "Item.h"

Level4::Level4() {};

void Level4::displayDescription(Player& p) 
{
	switch (p.getLocation4()) {

	//first case and player starts here, where the player meets the alchemist
	case Location4::CENTER_ROOM:
		//Current description of the center room of Level 4
		cout << "You are in a central area at the base of the tower. The Evil Alchemist stands before you." << endl;
		cout << "Four hallways extend from this room to other areas." << endl;
		break;

	case Location4::DOWN_ROOM:
		break;

	case Location4::RIGHT_ROOM:
		break;

	case Location4::LEFT_ROOM:
		break;

	case Location4::UP_ROOM:
		break;

	}
}

//For interaction based on player's input as seen in RealTeam2Game.cpp
//Takes input string
//Each room has interactions specific for the room so it matters which room they are in
void Level4::interact(Player& p, std::string input) {
	//Based on player's current location does specific run function
	switch (p.getLocation4()) {
	//Starting location
	case Location4::CENTER_ROOM:
		Level4::runCenterRoom(p, input);
		break;

	case Location4::DOWN_ROOM:
		Level4::runDownRoom(p, input);
		break;

	case Location4::RIGHT_ROOM:
		Level4::runRightRoom(p, input);
		break;

	case Location4::LEFT_ROOM:
		Level4::runLeftRoom(p, input);
		break;

	case Location4::UP_ROOM:
		Level4::runUpRoom(p, input);
		break;
	}
}

void Level4::runCenterRoom(Player& p, std::string input) {
	if (input == "down") {
		cout << "You go down" << endl;
		//Update location to DOWN_ROOM
		p.setLocation4(Level4::Location4::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation4(Level4::Location4::UP_ROOM);
		//Update location to UP_ROOM
	}
	else if (input == "left") {
		cout << "You go left" << endl;
		p.setLocation4(Level4::Location4::LEFT_ROOM);
		//Update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << "You go right" << endl;
		p.setLocation4(Level4::Location4::RIGHT_ROOM);
		//Update location to RIGHT_ROOM
	}
	else if (input == "leave") {
		cout << "You're in the Center Room" << endl << endl;
		p.setLocation4(Level4::Location4::CENTER_ROOM);
		//Update location to RIGHT_ROOM
	}
	//Code to go back to the previous floor which is the potion room
	else if (input == "ascend")
	{
		cout << "You went back to the previous room." << endl;
		p.setLevel(3);
		//Set level back to level 3
	}

}

void Level4::runUpRoom(Player& p, std::string input)
{
	cout << "There is nothing" << endl;
	p.setLocation4(Level4::Location4::CENTER_ROOM);
}

void Level4::runRightRoom(Player& p, std::string input)
{
	cout << "There is nothing" << endl;
	p.setLocation4(Level4::Location4::CENTER_ROOM);
}

void Level4::runDownRoom(Player& p, std::string input)
{
	cout << "There is nothing" << endl;
	p.setLocation4(Level4::Location4::CENTER_ROOM);
}

void Level4::runLeftRoom(Player& p, std::string input)
{
	cout << "There is nothing" << endl;
	p.setLocation4(Level4::Location4::CENTER_ROOM);
}