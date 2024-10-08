// RealTeam2Game.cpp
#include <iostream>
#include "Item.h"
#include "GameIntro.h"
#include "PuzzleIdeas.h"
#include "Room.h"

using namespace std;

int main()
{
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
}
