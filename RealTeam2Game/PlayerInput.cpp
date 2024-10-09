#include "PlayerInput.h"
#include "Item.h"
#include <iostream>

using namespace std;
PlayerInput::PlayerInput() : currentDirection("None"), torchFound(false), keyFound(false), riddleIsSolved(false)
{
    torch = Item("Torch"," A Flashlight");
    key = Item("key", " A metal key to unlock the door");

}



void PlayerInput::movePlayer(string direction)
{
	if (direction == "Up")
	{
        if (torchFound)
        {
            riddleVisible = true;
            currentDirection = "Up";
        }
        else
        {
            cout << "there is a riddle on the wall, but It's too dark to see anything!" << endl;
            currentDirection = "Up";
        }
		
        
	}
   
    else if (direction == "Down") {
        currentDirection = "Down";
    }
    else if (direction == "left") {
        currentDirection = "Left";

        if (!torchFound)
        {
            cout << "You found a torch! Use the command 'pick' to pick it up." << endl;
        }
    }
    else if (direction == "right") {
        currentDirection = "Right";
    }
    else {
        cout << "Invalid direction." << endl;
        return;
    }

}


// Handles item interaction (pickup, use, get)
void PlayerInput::itemInteraction(string command)
{
    if (command == "pickup" && !torchFound)
    {
        torchFound = true;
        cout << "You picked up the torch!" << endl;
    }
    else if (command == "use" && torchFound) {
        if (riddleVisible)
        {
            cout << "use the torch to see the riddle on the wall." << endl;
            cout << "Now solve the riddle on the wall to find the escape code." << endl;
            cout << "Riddle: In times of trouble, I’m the number you call,  A three - digit code for help, a lifeline for all. From fires to emergencies, I stand tall,What number am I, for safety's call?" << endl;
        }
        else {
            cout << "You need to move up to see the riddle" << endl;
        }
    }


    if (riddleVisible &&!riddleIsSolved)
    {
        string answer;
        cout << "Enter your answer: ";
        cin >> answer;
        if (answer == "911") {
            riddleIsSolved = true;
            cout << "You solved the riddle! The code is '911'. Now find the drawer to unlock it." << endl;
        }
        else {
            cout << "Incorrect answer. Try again." << endl;
        }
    }
    else if (!keyFound)
    {
        cout << "Enter the code to unlock the drawer: ";
        string code = "";
        cin >> code;
        if (code == "911")
        {
            keyFound = true;
            cout << "Drawer unlocked! You found the key. Use 'get' to take the key." << endl;
        }
        else
        {
            cout << "Wrong code. Try again." << endl;
        }
    }

   
    else if (command == "get"&& keyFound ) 
    {
        cout << "You got the key! Now find the door and unlock it with 'use key'." << endl;
    }
    else
    {
        cout << "Invalid command." << endl;
    }
}

// Checks if the player has found the torch
bool PlayerInput::hasTorch() const {
    return torchFound;
}

// Checks if the player has found the key
bool PlayerInput::hasKey() const {
    return keyFound;
}

// Checks if the riddle has been solved
bool PlayerInput::riddleSolved() const {
    return riddleIsSolved;
}
