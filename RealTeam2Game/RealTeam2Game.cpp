// RealTeam2Game.cpp
#include <iostream>
#include "Item.h"
#include "GameIntro.h"
#include "Level2.h"
#include "Level3.h"
#include "Player.h"
#include "PlayerInput.h"
#include "PuzzleIdeas.h"
#include "Room.h"
#include "StopWatch.h"

using namespace std;

int main()
{
    StopWatch GameTime;
    Backstory();
    Controls();
    

    //Test cases - commented out for now
    /*
    Room test("Dark room", "HMMMMMMM, it's dark", 0);
    test.GetRoomName();
    test.GetRoomDescript();

    std::cout << "Hello World!\n";
    Item pencil("Pencil", "A tool for writing");
    std::cout << pencil.getDisplayName() << endl;
    std::cout << pencil.getDescription() << endl;
    pencil.setDisplayName("Pen");
    pencil.setDescription("A tool for wriitng in ink");
    std::cout << pencil.getDisplayName() << endl;
    std::cout << pencil.getDescription() << endl;
    */

    //Bool check to enable ability to go back to previous rooms
    bool gameRunning = true;
   
    PlayerInput inputHandler;
    Player player;

    player.setLevel(3); //for testing only

    string input;


    //While loop to check the gameRunning value
    while (gameRunning)
    {
        cout << "Welcome to the Escape Room Game!" << endl;
        

        while (player.getLevel() == 1) {
            cout << "Enter next command (up, down, left, right, use, pickup, get, insert): ";
            cin >> input;
            clearScreen();

            if (input == "up" || input == "down" || input == "left" || input == "right" || input == "center") {
                inputHandler.movePlayer(input);
            }
            else if (input == "use" || input == "pickup" || input == "get" || input == "insert") {
                inputHandler.itemInteraction(input, GameTime);
            }
            else if (input == "descend") {
                inputHandler.descend(player);
            }
            else {
                cout << "Invalid command." << endl;
            }
        }

        //level objects 1 for each level except for the first level
        Level2 level2;
        //Level3 level3;

        //this will keep the player in the level still able to enter another command after the next as well as get input
        //stops once they are no longer on level 2
        while (player.getLevel() == 2) {
            level2.displayDescription(player);
            cout << "Enter a command: ";
            cin >> input;
            clearScreen();
            level2.interact(player, input);
        }
        
        //TODO: cout "time spent so far L2" 
        GameTime.printDiffTime(); 


        //Level 3 object creation
        Level3 level3;

        
       
        //While loop to keep player in Level 3 and allow them to input commands to solve the puzzles in the room
        //Breaks when level is no longer 3
        while (player.getLevel() == 3) {
            level3.displayDescription(player);
            cout << "Enter a command: ";
            cin >> input;
            clearScreen();
            level3.interact(player, input);
        }
        //TODO: cout "time spent so far L3" 
        GameTime.printDiffTime();
    }
    return 0;
}