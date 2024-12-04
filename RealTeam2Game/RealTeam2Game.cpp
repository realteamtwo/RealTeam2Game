// RealTeam2Game.cpp
#include <iostream>
#include "Item.h"
#include "GameIntro.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"
#include "Player.h"
#include "PlayerInput.h"
#include "PuzzleIdeas.h"
#include "Room.h"
#include "StopWatch.h"
#include <string>
#include "Inventory.h"

using namespace std;

int main()
{
    StopWatch GameTime;
    Backstory();
    Controls();

    bool level1Cleared = false;
    bool level2Cleared = false;
    bool level3Cleared = false;
    bool level4Cleared = false;

    bool level2StartedRoom = false;
    bool level3StartedRoom = false;
    bool level4StartedRoom = false;


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

    //Uncomment to skip to another level, for testing
    //player.setLevel(3);

    //Uncomment to give the player the worms item
    //Recommended for manually testing level 3 without having to play through level 2
    //player.addItem(Item("Worms", "A jar of earthworms squirming around"));
    

    string input;
        // Create an inventory object
        /*Inventory inventory;

        // Add some items to the inventory
        inventory.addItem(Item("Sword", "A sharp blade"));
        inventory.addItem(Item("Shield", "A strong shield"));

        std::string command;

        // Game loop
        while (true) {
            std::cout << "Enter a command (type 'help' for options): ";
            std::getline(std::cin, command);

            if (command == "inventory") {
                // Show inventory
                inventory.showInventory();
            }
            else if (command == "exit") {
                // Exit the inventory screen and return to the game
                std::cout << "Exiting inventory..." << std::endl;
                break;  // This breaks out of the loop, simulating return to the game
            }
            else if (command == "help") {
                std::cout << "Commands: 'inventory', 'exit', 'use [item_name]'" << std::endl;
            }
            else if (command.rfind("use ", 0) == 0) {
                // Use an item from inventory
                std::string itemName = command.substr(4);  // Get the item name after "use "
                inventory.useItem(itemName);
            }
            else {
                std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
            }
        }
        */
    //While loop to check the gameRunning value

    //Level object creation
    Level2 level2;
    Level3 level3;
    Level4 level4;

    while (gameRunning)
    { 

        while (player.getLevel() == 1) {
            cout << "Enter next command (up, down, left, right, use, pickup, get, insert): ";
            cin >> input;
            clearScreen();
            cout << "[Level 1 - Dark Room]" << endl;

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

            if (level1Cleared == false && inputHandler.checkWin())
            {
                //TODO: cout "time spent so far L2" 
                cout << "Current Game Time: ";
                GameTime.printDiffTime();
                level1Cleared = true;
            }
            else
            {
                cout << "\n" << "Current level Time: ";
                GameTime.printDiffTime();
            }
        }

     

        //this will keep the player in the level still able to enter another command after the next as well as get input
        //stops once they are no longer on level 2
        while (player.getLevel() == 2) {
            if (level2StartedRoom == false)
            {
                level2.resetStopwatch();
                level2StartedRoom = true;
            }
            level2.displayDescription(player);
            cout << "Enter a command: ";
            cin >> input;
            clearScreen();
            cout << "[Level 2 - Riddle Rooms]" << endl;
            level2.interact(player, input);
            cout << "Current Game Time: ";
            GameTime.printDiffTime();
            if (level2Cleared == false && level2.checkWin(player))
            {
                level2Cleared = true;
            }
        }
        
       

        //While loop to keep player in Level 3 and allow them to input commands to solve the puzzles in the room
        //Breaks when level is no longer 3
        while (player.getLevel() == 3) {
            if (level3StartedRoom == false)
            {
                level3.resetStopwatch();
                level3StartedRoom = true;
            }
            level3.displayDescription(player);
            cout << "Enter a command: ";
            cin >> input;
            clearScreen();
            cout << "[Level 3 - Potion Room]" << endl;
            level3.interact(player, input);
            cout << "Current Game Time: ";
            GameTime.printDiffTime();
            if (level3Cleared == false && level3.checkWin())
            {
                level3Cleared = true;
            }
        }

        //While loop to keep player in Level 4 and allow them to input commands to solve the puzzles in the room
        //Breaks when level is no longer 4
        while (player.getLevel() == 4) {
            if (level4StartedRoom == false)
            {
                level4.resetStopwatch();
                level4StartedRoom = true;
            }
            level4.displayDescription(player);
            cout << "Enter a command: ";
            cin >> input;
            clearScreen();
            cout << "[Level 4 - The Alchemist's Lair]" << endl;
            level4.interact(player, input);
            cout << "Current Game Time: ";
            GameTime.printDiffTime();
            if (level4Cleared == false && level4.checkWin())
            {
                //TODO: cout "time spent so far L4" 
                level4Cleared = true;
            }
        }
    }
    return 0;
}