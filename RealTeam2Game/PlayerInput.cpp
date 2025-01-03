#include "PlayerInput.h"
#include <iostream>
#include "StopWatch.h"
using namespace std;

PlayerInput::PlayerInput() : currentDirection("Center"), matchFound(false), torchFound(false), keyFound(false), riddleVisible(false), riddleIsSolved(false), drawerUnlocked(false), doorUnlocked(false)
{
    match = Item("Match", " A spark of fire");
    torch = Item("Torch", "A Flashlight");
    key = Item("Key", "A metal key to unlock the door");
    rock = Item("Rock", "A blunt rock from the Earth Room");
    fireextinguisher = Item("Fire Extinguisher", "Used to put out fires"); 
    matchstick = Item("Matchstick", "A single matchstick");


  //  cout << "You are at the center of the room. It's dark, but you sense something important." << endl;
  //  cout << "Hint: Go left to find a torch!" << endl;

}

// Function to handle player movement
void PlayerInput::movePlayer(string direction) {

    if (direction == "up" || direction == "Up") {
        cout << " current location:"<<endl;
        cout << "     | P |           " << endl;
        cout << "|///|     |///|" << endl;
        cout << "     |///|     " << endl;
        if (riddleIsSolved)
        {
            cout << "You already solved a riddle. Now you need to find the drawer." << endl;
        }
        else  if (torchFound) {
            riddleVisible = true;
            currentDirection = "Up";
            cout << "You moved up. There is a riddle on the wall." << endl;
            cout << "You will only see the riddle if you use the torch, input 'use' to turn on the torch" << endl;
        }
        else
        {
            cout << "It's too dark to see the riddle on the wall. You need a torch!" << endl;

        }
    }



    else if (direction == "down"|| direction == "Down") {
        currentDirection = "Down";
        cout << " current location:" << endl;
        cout << "     |///|           " << endl;
        cout << "|///|     |///|" << endl;
        cout << "     | P |     " << endl;
        cout << "You moved down." << endl;
        if (doorUnlocked) {
            cout << "The door to the next floor is still unlocked, but you see something else." << endl;
            cout << "Scratched into the door is a four-word phrase. The first word is illegible." << endl;
            cout << "\"?????? AND THANK YOU\"" << endl;
        }
        else if (keyFound)
        {
            cout << "You found the door! Insert the key to unlock it, by typing 'insert'. " << endl;
        }
        else {
            cout << "You need to find the key to unlock the door. " << endl;
        }
    }
    else if (direction == "left"|| direction=="Left") {
        currentDirection = "Left";
        cout << " current location:" << endl;
        cout << "     |///|           " << endl;
        cout << "| P |     |///|" << endl;
        cout << "     |///|     " << endl;
        if (!torchFound) {
            cout << "You found a torch! Use the command 'pickup' to pick it up." << endl;
        }
        else {
            cout << "Nothing more to find here" << endl;
        }
    }
    else if (direction == "right" || direction == "Right") {
        currentDirection = "Right";
        cout << " current location:" << endl;
        cout << "     |///|           " << endl;
        cout << "|///|     | P |" << endl;
        cout << "     |///|     " << endl;
        if (riddleIsSolved && !drawerUnlocked) {

            cout << "You found a drawer. Use the code you got from the riddle to unlock it." << endl;
            string code;
            cout << "Enter the code: ";
            cin >> code;
            if (code == "911"|| code == "999")
            {
                drawerUnlocked = true;
                keyFound = true;
                cout << "You unlocked the drawer and found the key! Use the 'get' command to retrieve it." << endl;
            }

            else
            {
                cout << "Incorrect code. Try Again." << endl;
            }
        }

        else {

            cout << "You moved right." << endl;
        }
    }
    else {
        cout << "Invalid direction." << endl;
        return;
    }}

// Function to handle item interaction (pickup, use, get)
void PlayerInput::itemInteraction(string command, StopWatch GameTime) {
    if (command == "pickup" && !torchFound && currentDirection == "Left") {
        torchFound = true;
        cout << "You picked up the torch! Now move up to see the riddle." << endl;
    }

    else if (command == "pickup rock" || command == "Pickup rock" && !rockFound)
    {
        rockFound = true;
        cout << "You picked up the rock!" << endl;
    }

    else if (command == "use"&& torchFound) {
        if (riddleVisible && !riddleIsSolved) {
            cout << "You used the torch to see the riddle on the wall." << endl;
            cout << "Riddle: In times of trouble, I'm the number you call, a three-digit code for help, a lifeline for all. From fires to emergencies, I stand tall. What number am I?" << endl;
            string answer;
            cout << "Enter your answer: ";
            cin >> answer;


            if (answer == "911"|| answer=="999")
            {
                riddleIsSolved = true;
                cout << "You solved the riddle! Now find the drawer and unlock it." << endl;
            }
            else {
                cout << "Incorrect answer. Try again." << endl;
            }
        }
    
        else{
            cout << "You need to move up to see the riddle." << endl;
        }

    }
   
    
    else if (command == "get" || command == "Get") {
        if (keyFound && drawerUnlocked) {
            cout << "You got the key! Now find the door and use the key to unlock it." << endl;
        }
        else if (!drawerUnlocked) {
            cout << "You need to unlock the drawer first with the code." << endl;
        }
    }
    else if (command == "insert" && keyFound && currentDirection == "Down") {
        {
            if (doorUnlocked) {
                cout << "You already unlocked the door." << endl;
            }
            else {
                cout << "You inserted the key to unlock the door." << endl;
                cout << "Congratulations! You have unlocked the door!" << endl;
                cout << "Type \"descend\" to go to the next floor." << endl;

                // How much time has passed in the game overall since beating level 1
                cout << "\n" << "Level #1 has been completed in: ";
                GameTime.printDiffTime();

                doorUnlocked = true;
                //exit(0);
            }
        }
    }
    else {
        cout << "Invalid command." << endl;
    }

    /*  else if
      if (command == "pickup match" && !matchFound && currentDirection == "Left") {
          matchFound = true;
          cout << "You picked up the Matches! Now move up to see the riddle." << endl;
      }

       else if (command == "Light" || command == "Light") {
      if (matchFound && torchUnlocked) {
          cout << "You got the match! Now Use the Torch and light the fire again." << endl;
      }
      else if (!torchUnlocked) {
          cout << "You need to pickup the torch first in order to light a fire." << endl;
      }*/

}

//Function to handle descending to the next floor
void PlayerInput::descend(Player &player) {
    if (doorUnlocked == true) {
        player.setLevel(2);
        player.setLocation(Level2::Location::CENTER_ROOM);
    }
    else {
        cout << "You can't do that yet!" << endl;
    }
}


// Checks if the player has found the torch

bool PlayerInput::hasMatch() const {
    return matchFound;
}

bool PlayerInput::hasTorch() const {
    return torchFound;
}

// Checks if the player has found the key
bool PlayerInput::hasKey() const {
    return keyFound;
}

bool PlayerInput::hasRock() const
{
    return rockFound;
}

// Checks if the riddle has been solved
bool PlayerInput::riddleSolved() const {
    return riddleIsSolved;
}