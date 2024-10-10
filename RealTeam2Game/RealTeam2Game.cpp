// RealTeam2Game.cpp
#include <iostream>
#include "Item.h"
#include "GameIntro.h"
#include "PlayerInput.h"
#include "PuzzleIdeas.h"
#include "Room.h"

using namespace std;

int main()
{
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

    string input;
    while (true) {
        cout << "Enter next command: ";
        cin >> input;
        if (input == "Up" || input == "Down" || input == "left" || input == "right") {
            cout << "Command recieved" << endl;
            inputHandler.movePlayer(input);
        }
        else if (input == "use" || input == "get" || input == "pickup") {
            cout << "Command recieved" << endl;
            inputHandler.itemInteraction(input);
        }
    }
}
