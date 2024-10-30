#include "Level2.h"
#include "Player.h"


Level2::Level2(): fireextinguisherFound(false), matchstickFound(false), rightRoomEntered(false){
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
        if (!rightRoomEntered) {
            cout << "You move right to a room with light gleaming and intense heat suffocating you" << endl;
            rightRoomEntered = true;
        }
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
	cout << "Center Room Interaction (Placeholder)" << endl;
	if (input == "down") {
		cout << " you go down " << endl;
		p.setLocation(Level2::Location::DOWN_ROOM);  
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation(Level2::Location::UP_ROOM);
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " you go left" << endl;
		//p.setLocation(Level2::Location::LEFT_ROOM);
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " you go right" << endl;
		p.setLocation(Level2::Location::RIGHT_ROOM);
		//update location to RIGHT_ROOM
	}
}

void Level2::runDownRoom(Player &p, std::string input) {
	cout << "Down Room Interaction (Placeholder)" << endl;
}

void Level2::runRightRoom(Player& p, std::string input) {
	cout << "FIRE ROOM" << endl;
   
 // Left wall interaction: Fire extinguisher riddle
    if (input == "left") {
            if (!fireextinguisherFound) {
                cout << "The left wall has a riddle:\n"
                    << "\"I can stop flames, but I’m not water. You spray me to put out fire. What am I?\"\n";
                cout << "Enter your answer: ";
                string answer;
                cin >> answer;

                if (answer == "fireextinguisher") {
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
                    // Logic for unlocking the door goes here...
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

        // Up wall interaction: Riddle to get the matchstick
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

                    if (answer == "matchstick") {
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
}