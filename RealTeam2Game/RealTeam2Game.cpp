// RealTeam2Game.cpp
#include <iostream>
#include "Item.h"
#include "GameIntro.h"
#include "Level2.h"
#include "Player.h"
#include "PlayerInput.h"
#include "PuzzleIdeas.h"
#include "Room.h"

using namespace std;

int main()
{
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

   
    PlayerInput inputHandler;
    Player player;

    cout << "Welcome to the Escape Room Game!" << endl;
    cout << "You are at the center of the room. It's dark, but you sense something important is in this room." << endl;
    cout << "Hint: Move left to find a torch." << endl;

    string input;

    while (player.getLevel() == 1) {
        cout << "Enter next command (up, down, left, right, use, pickup, get, insert): ";
        cin >> input;

        if (input == "up" || input == "down" || input == "left" || input == "right" || input == "center") {
            inputHandler.movePlayer(input);
        }
        else if (input == "use" || input == "pickup" || input == "get" || input == "insert") {
            inputHandler.itemInteraction(input);
        }
        else if (input == "descend") {
            inputHandler.descend(player);
        }
        else {
            cout << "Invalid command." << endl;
        }
    }
    
    Level2 level2;

    while (player.getLevel() == 2) {
        level2.displayDescription(player);
        cout << "Enter a command: ";
        cin >> input;
        level2.interact(player, input);
    }

    return 0;
}