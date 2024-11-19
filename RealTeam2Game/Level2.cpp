#include "Level2.h"
#include "Player.h"
#include "Item.h"

Item SharpRock;
Item JarOfEarthworms;

Level2::Level2() : fireextinguisherFound(false), matchstickFound(false), rightRoomEntered(false), sharpRockFound(false), jarOfEarthwormsFound(false), glassBroken(false) {}

bool fireSolved = false;
bool waterSolved = false;
bool earthSolved = false;
bool airSolved = false;

bool doorUnlocked = false;

void Level2::displayDescription(Player &p) {
	switch (p.getLocation()) {
	case Location::CENTER_ROOM:
		if (fireSolved && waterSolved && earthSolved && airSolved) {
			cout << "You hear a click from the center of the room." << endl;
			cout << "You are in a central area with an open trapdoor." << endl;
			if (doorUnlocked == false)
			{
				// How much time has passed in the game overall since beating level 2
				cout << "\n" << "Level #2 has been completed in: ";
				L2Time.printDiffTime();
				doorUnlocked = true;
			}
		}
		else {
			cout << "You are in a central area with another locked trapdoor." << endl;
		}
		cout << "Four hallways extend from this room to other areas." << endl;
		break;
	////is this how you want the format of the code? -Nicole
	// 
	//for the air room
	case Location::DOWN_ROOM:
		cout << "You are in a room with writing on the walls. A breeze passes by you"<< endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		//for fire room
	case Location::RIGHT_ROOM:

        if (!rightRoomEntered) {
            cout << "You move right to a room with light gleaming and intense heat suffocating you" << endl;
            rightRoomEntered = true;
        }

		cout << "You are in a room with light gleaming and intense heat suffocating you" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;

		break;
		//for water room
	case Location::LEFT_ROOM:
		cout << "You are in a room with the smell of the ocean and beautiful sea creatures around in a tank" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		//for earth room
	case Location::UP_ROOM:
		cout << "The room you are within has rock walls and a dirt floor, and you are overwhelmed by a sandstorm engulfing the room" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
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
		cout << "You go down " << endl;
		//update location to DOWN_ROOM
		p.setLocation(Level2::Location::DOWN_ROOM); 
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation(Level2::Location::UP_ROOM);
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << "You go left" << endl;
		p.setLocation(Level2::Location::LEFT_ROOM);
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << "You go right" << endl;
		p.setLocation(Level2::Location::RIGHT_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "leave") {
		cout << "You're in the Center Room" << endl << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "descend") {
		// Level 2 Completed
		if (fireSolved && waterSolved && earthSolved && airSolved) {
			cout << "You go down through the trapdoor to the next floor of the tower." << endl;
			p.setLevel(3);
		}
		else {
			cout << "The trapdoor is locked!" << endl;
		}
		
	}

}

void Level2::runDownRoom(Player &p, std::string input) {
	
	if (input == "down") {
		cout << "What travels in the daylight but casts no shadow? What can you feel but you cannot see? Say your answer" << endl;
	}

	else if (input == "left") {
		cout << "The wall is decorated with swirls" << endl;
	}

	else if (input == "right") {
		cout << "There are many pinwheels huddled together here " << endl;
	}

	else if (input == "up") {
		cout << "The doorway you came from has many tassels and cloth flowing in the breeze" << endl;
	}
	else if (input == "leave") {
		cout << "You leave the Air Room" << endl << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
	else if(input == "air") {
		cout << "You solved the riddle!" << endl;
		//maybe get item air key or update an unlocking variable (going with variable for now)
		airSolved = true;
	}
}

void Level2::runRightRoom(Player& p, std::string input) {

	cout << "FIRE ROOM" << endl;

	/*cout << "Right Room Interaction" << endl;

	if (input == "down") {
		cout << "Do Your Work 4 down:)" << endl;
	}

	else if (input == "left") {
		cout << "Do Your Work 4 left :)" << endl;
	}

	else if (input == "right") {
		cout << "Do Your Work 4 right :)" << endl;
	}

	else if (input == "up") {
		cout << "Do Your Work 4 up :)" << endl;
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
	else if (input == "fire") {
		//put some kind of cout statement
		riddlesSolved++;
	}
	*/
	// Left wall interaction: Fire extinguisher riddle
	if (input == "left") {
		if (!fireextinguisherFound) {
			cout << "The left wall has a riddle:\n"
				<< "\"I can stop flames, but I’m not water. You spray me to put out fire. What am I?\"\n";
			cout << "Enter your answer: ";
			string answer;
			cin >> answer;

			if (answer == "fireextinguisher" || answer == "fire extinguisher") {
				cout << "Correct! You've obtained the Fire Extinguisher!\n";
				fireextinguisherFound = true;
				cout << "Go to another wall in order to escape.\n";
			}
			else {
				cout << "Incorrect answer. Try again!\n";
			}
		}
		else {
			cout << "You have already collected the Fire Extinguisher.\n";
		}
	}

	// Down wall interaction: Burned picture and shortcut option
	else if (input == "down") {
		cout << "The down wall shows a burned picture with family members. A message next to it reads:\n"
			<< "\"If you want a shortcut to escape, find the code hidden in this picture.\"\n";
		cout << "WARNING: If you take this shortcut, it will count as a halfly solved room, which will impact your score.";


		// Ask if the user wants to take the shortcut
		cout << "Do you still want to take this shortcut? (Y/N): ";
		char choice;
		cin >> choice;

		if (toupper(choice) == 'Y') {
			// Provide the picture description and riddle question
			cout << "It's a partially cut picture showing a family with a mom, dad, two sons, and a daughter, it's burnt from the left corner. "
				<< "The mom was standing on the left corner of the photo.\n";
			cout << "How many members do you see clearly in the picture? ";
			int answer;
			cin >> answer;

			if (answer == 4) {
				cout << "Correct! You got it. The window is now open, and you can jump out to escape.\n";
				cout << "input 'jump' in order to jump off the window" << endl;
			}
			else {
				cout << "Incorrect answer. You didn't find the shortcut.\n";
			}
		}
		else if (toupper(choice) == 'N') {
			// If the user does not want to take the shortcut, prompt for the next command
			cout << "Enter the next command to move to another wall or take a different action.\n";
		}
		else {
			cout << "Invalid choice. Please enter 'Y' or 'N'.\n";
		}
	}
	else if (input == "jump") {
		cout << "You jump out of the window and exit the fire room successfully!\n";
		// Update player’s location or end the room interaction
		p.setLocation(Level2::Location::CENTER_ROOM); // or another exit location as per game design
	}
	// Right wall interaction: Door with matchstick lock puzzle
	else if (input == "right") {
		if (matchstickFound) {
			cout << "The right wall has a locked door with a red phosphorus on it.\n";
			cout << " use the matchstick by inputting 'U' to unlock yourself from the fire riddle room : ";
			char choice;
			cin >> choice;

			// If the player chooses to use the matchstick
			if (toupper(choice) == 'U') {
				cout << "You use the matchstick on the red phosphorus." << endl;
				cout << "You see something illuminating. This brings to mind a riddle." << endl;
				cout << "\"What did you see after using the matchstick?\"\n";
				cout << "Enter the answer to unlock the door: ";

				// Get user input for the riddle
				string answer;
				cin >> answer;

				// Check if the answer is correct
				if (answer == "fire" || answer == "flames" || answer == "smoke") {
					cout << "The door unlocks as you answered correctly!" << endl;
					fireSolved = true;
					p.setLocation(Level2::Location::CENTER_ROOM); // Move to the next location or room
				}
				else {
					cout << "That's not the right answer. Try again." << endl;
				}
			}
			else {
				cout << "You chose not to use the matchstick. Please enter another command." << endl;
			}
		}

		else {
			cout << "The door is locked with a puzzle. Perhaps solving another riddle will help.\n";
		}
	}
	else if (input == "up") {
		if (fireextinguisherFound) {
			cout << "There’s a fire on the wall.\n"
				<< "Use an item from your inventory to clear the fire: ";
			string item;
			cin >> item;
			if (item == "fireextinguisher") {
				cout << "You used the Fire Extinguisher to clear the flames! The path is now accessible.\n";
				cout << "The wall reads:" << endl;
				cout << "I am often found in a box," << endl;
				cout << "Strike me once, and I’ll make sparks," << endl;
				cout << "I can help you start a fire,  Or light up darkened parks." << endl;
				cout << "What am I?" << endl;
				cout << "Enter your answer: ";
				string answer;
				cin >> answer;
				if (answer == "matchstick" || answer == "match") {
					cout << "Correct! You've obtained a matchstick.\n";
					matchstickFound = true;
					cout << "Go to another wall in order to escape.\n";
				}
				else {
					cout << "Incorrect answer. Try again.\n";
				}
			}
			else {
				cout << "That item can't be used to clear the fire.\n";
				cout << "Please enter a diffeent item or try again.\n";
			}
		}
		else {
			cout << "There’s a fire blocking your way. You need something to clear it first.\n";
		}
	}
	else {
		cout << "Invalid direction. Please enter 'up', 'down', 'left', or 'right'.\n";
	}
}
void Level2::runLeftRoom(Player& p, std::string input) {
	cout << "Left Room Interaction" << endl;
	cout << "Water Room" << endl;

	if (input == "down") {
		cout << "The back glass of the aquarium room wall is vibrant. " << endl;
		cout << "All there seems to be is a bunch of ancient greek designs of poseidon...Welp nothing I can do about this." << endl;
	}
	else if (input == "up") {
		cout << "The front wall is empty with no water and a huge crack in the middle like a sea creature bust through it" << endl;
	}

	else if (input == "left") {
		cout << "The left glass of the aquariaum is covered with moss, plants and a slight crack in the glass." <<endl;
		cout << "A chunk of glass seems to have broken off onto the floor." << endl;
		cout << "Within the decrypted messages on the broken markings.\n [It States] What runs but has no feet? .\n roars but has no mouth? .\n Runs but never gets tired? .\n " << endl;
		cout << "What Am I ?" << endl;

	}
	else if (input == "right") {
		cout << "The right glass wall holds beautiful sea creatures from all over the world" << endl;
	}
	else if (input == "water") {
		cout << "You solved the riddle!" << endl;
		waterSolved = true;
	}
	else if (input == "leave") {
		cout << "You leave the Water Room" << endl << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
		}
	
	
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
		if (!sharpRockFound)
		{
			cout << " You see a Sharp Rock in the dirt" << endl;
			cout << "  Do you want to pickup?(y/n)";
			string choice;
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				cout << " You picked up the Sharp Rock." << endl;
				sharpRockFound = true;
				p.addItem(SharpRock);// Add the rock to the player's Inventory
			}
		
		else {
			cout << "You leave the rock in the dirt.\n";
		}
	}
	else {
		cout << "You already picked up the rock.\n";
	}
		
		
	}
	else if (input == "right") {
		if (!sharpRockFound) { // Rock is needed to break the glass
			cout << "You see a glass jar behind a barrier, but you need something sharp to break it." << endl;
		}
		else if (!glassBroken) { // Rock available, glass not broken yet
			cout << "Use the sharp rock to break the glass? (y/n): ";
			string choice;
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				cout << "You smash the glass with the sharp rock. The jar is now accessible." << endl;
				glassBroken = true;

				if (!jarOfEarthwormsFound) { // Glass is broken, jar not picked up yet
					cout << "Pick up the jar of earthworms: ";
					string choice;
					cin >> choice;
					if (choice == "pickup") { // If the player chooses to pick up the jar
						cout << "You picked up the jar of earthworms.(~~~)"<<endl;
						cout << "                                    (~~~)" << endl;
						jarOfEarthwormsFound = true;
						p.addItem(JarOfEarthworms); // Add the jar to the player's inventory
					}
					else {
						cout << "You leave the jar where it is.\n";
					}
				}
				else { // Jar already picked up
					cout << "You already have the jar of earthworms.\n";
				}
			}
			else {
				cout << "You decide not to break the glass for now." << endl;
			}
		}
		
		
	}
	else if (input == "earth")
	{
		cout << "You solved the riddle!" << endl;
		earthSolved = true;
	}

	else if (input == "leave") {
		cout << "You leave the Earth Room" << endl << endl;
		p.setLocation(Level2::Location::CENTER_ROOM);
	}
}