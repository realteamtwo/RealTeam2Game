//cpp for Level 4 (The Alchemist's Room) will be where location descriptions snd interactions for the player will be
#include "Level4.h"
#include "Player.h"
#include "Item.h"

Level4::Level4() 
{
	riddleOneSolved = false;
	riddleTwoSolved = false;
	riddleThreeSolved = false;
};

void Level4::displayDescription(Player& p) 
{
	switch (p.getLocation4()) {

	//first case and player starts here, where the player meets the alchemist
	case Location4::CENTER_ROOM:
		//Current description of the center room of Level 4
		//Encounter the alchemist and start the process of the final set of riddles
		cout << "You are in a central area at the base of the tower. The Evil Alchemist stands before you." << endl;
		cout << "'You have done well to make it this far, but believe me. Escaping this tower will not be so simple' he says." << endl;
		cout << "'On this final floor resides your final riddles to solve. If you solve them, you may leave, but if you cannot, you will remain here forever!" << endl;
		cout << "You will need to use all of the tower's resources to solve this challenge. Some clues may be lying in other parts of the tower." << endl;
		cout << "Prove to me that you deserve to escape, or remain here with me as my test subject for eternity!'" << endl << endl;
		//First riddle prompt from the Evil Alchemist, checks that the first riddle hasn't been solved yet
		if (riddleOneSolved == false)
		{
			cout << "Your first riddle is: 'What kind of agreement can be transmuted from lead?' Perhaps the Potions Room can be of help." << endl;
		}
		//Second riddle prompt from the Evil Alchemist, checks that the first riddle has been solved and the second hasn't yet
		else if (riddleOneSolved == true && riddleTwoSolved == false)
		{
			cout << "Your second riddle is: 'I am an element, but also a feeling. I am used by warmongers and storytellers alike. What am I' Perhaps the Elemental Room can be of help." << endl;
		}
		//Third riddle prompt from the Evil Alchemist, checks that the first and second riddle has been solved and the third hasn't yet
		else if (riddleOneSolved == true && riddleTwoSolved == true && riddleThreeSolved == false)
		{
			cout << "Your third and final riddle is: 'What word of magic should everyone know?' Perhaps the Dark Room can be of help." << endl;
		}
		//Check to allow the player to leave after all three riddles have been solved
		else if (riddleOneSolved == true && riddleTwoSolved == true && riddleThreeSolved == true)
		{
			cout << "The Evil Alchemist grins at you. 'You have proved your worth, you may go ... for now. Type 'exit' to exit my tower." << endl;
		}
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

bool Level4::checkWin() const
{
	// To Do, Replace (False) with level 4 win condition.
	return false;
}

void Level4::resetStopwatch()
{
	L4Time.reset();
}

void Level4::runCenterRoom(Player& p, std::string input) {
	if (input == "down") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     | P |     " << endl;
		cout << "You go down" << endl;
		//Update location to DOWN_ROOM
		p.setLocation4(Level4::Location4::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << " current location:" << endl;
		cout << "     | P |           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << "You go up" << endl;
		p.setLocation4(Level4::Location4::UP_ROOM);
		//Update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "| P |     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << "You go left" << endl;
		p.setLocation4(Level4::Location4::LEFT_ROOM);
		//Update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     | P |" << endl;
		cout << "     |///|     " << endl;
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
	//Input handling for first riddle, ensures first riddle isn't solved yet
	else if ((input == "deal" || input == "DEAL" || input == "Deal") && riddleOneSolved == false)
	{
		cout << "The First Riddle has been solved!" << endl;
		riddleOneSolved = true;
	}
	//Input handling for second riddle, ensures second riddle isn't solved yet but the first riddle is 
	else if ((input == "surprise" || input == "SURPRISE" || input == "Surprise") && riddleOneSolved == true && riddleTwoSolved == false)
	{
		cout << "The Second Riddle has been solved!" << endl;
		riddleTwoSolved = true;
	}
	//Input handling for third riddle, ensures third riddle isn't solved yet but the first and second riddle are 
	else if ((input == "please" || input == "PLEASE" || input == "Please") && riddleOneSolved == true && riddleTwoSolved == true && riddleThreeSolved == false)
	{
		cout << "The Third and Final Riddle has been solved!" << endl;
		riddleThreeSolved = true;
	}
	//Input handler to check for the exit condition and allow the player to leave the tower and finish the game
	else if ((input == "exit" || input == "EXIT" || input == "Exit") && riddleOneSolved == true && riddleTwoSolved == true && riddleThreeSolved == true)
	{
		cout << "You exit the tower having escaped the Evil Alchemist unharmed." << endl;
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