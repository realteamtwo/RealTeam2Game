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

//tictactoe code variables
void drawBoard(char* spaces);
void playerMove(char* spaces, char player);
void computerMove(char* spaces, char computer);
bool checkWinner(char* spaces, char player, char computer);
bool checkTie(char* spaces);
int ticWins = 0;
//tictactoe code
void playGame() {
	while (ticWins < 3) {
		char spaces[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
		char player = 'X';
		char computer = 'O';
		bool running = true;
		drawBoard(spaces);

		while (running) {
			playerMove(spaces, player);
			drawBoard(spaces);
			if (checkWinner(spaces, player, computer)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}

			computerMove(spaces, computer);
			drawBoard(spaces);
			if (checkWinner(spaces, player, computer)) {
				running = false;
				break;
			}
			else if (checkTie(spaces)) {
				running = false;
				break;
			}
		}
		cout << "I'll show you!" << endl;
	}
}

void drawBoard(char* spaces) {
	cout << '\n';
	//making the board (the spaces don't look like they line up but they do)
	cout << "     |     |     " << endl;
	cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
	cout << "     |     |     " << endl;
	cout << '\n';
}
void playerMove(char* spaces, char player) {
	int number;
	while (number < 0 || number > 8) {
		cout << "Enter (1-9) to pick a square to place marker: ";
		cin >> number;
		number--;
		if (spaces[number] == ' ') {
			spaces[number] = player;
			break;
		}
	}
	
}
void computerMove(char* spaces, char computer) {
	int number;
	srand(time(0));
	//random number
	while (true) {
		number = rand() % 9;
		if (spaces[number] == ' ') {
			spaces[number] = computer;
			break;
		}
	}
}
bool checkWinner(char* spaces, char player, char computer) {

	if ((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2])) {
		if (spaces[0] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha\n";
		}
	}
	else if ((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5])) {
		if (spaces[3] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8])) {
		if (spaces[6] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6])) {
		if (spaces[0] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7])) {
		if (spaces[1] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8])) {
		if (spaces[2] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8])) {
		if (spaces[0] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else if ((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6])) {
		if (spaces[2] == player) {
			cout << "YOU WIN!" << endl;;
			ticWins++;
		}
		else {
			cout << "YOU LOSE! Muahahaha" << endl;
		}
	}
	else {
		return false;
	}

	return true;
}
bool checkTie(char* spaces) {

	for (int i = 0; i < 9; i++) {
		if (spaces[i] == ' ') {
			return false;
		}
	}
	cout << "IT'S A TIE!\n";
	return true;
}





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
		cout << "But before that I challenge you to a little game" << endl;

		cout << "The Evil Alchemist has challenged you to Tic-Tac-Toe" << endl;
		cout << "Defeat him 3 times to move on" << endl;
		playGame();
		cout << "I'll get you for this" << endl;

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

bool Level4::getRiddleSolved(int riddleNum) {
	switch (riddleNum) {
	case 1:
		return riddleOneSolved;
		break;
	case 2:
		return riddleTwoSolved;
		break;
	case 3:
		return riddleThreeSolved;
		break;
	default:
		return false;
		break;
	}
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
		cout << "  u   |///|     " << endl;
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

		if (doorunlocked == false)
			{
				// How much time has passed in the game overall since beating level 2
				cout << "\n" << "Level #4 has been completed in: ";
				L4Time.printDiffTime();
				doorunlocked = true;
			}
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