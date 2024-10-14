#include <iostream>
#include "GameIntro.h"

using namespace std;

void Backstory() {
	
	cout << "A teleportation spell has gone wrong and you find yourself in an unfamiliar room. You must seek a way out, traveling down until you reach the ground level to flee the evil alchemist's tower!" << endl;
}

void Controls() {
	cout << "To descend the Tower, you must open the trapdoor in the middle of each room," << "which will often be locked in some way. The method to do so is hidden in the room. Investigate, solve puzzles and use items.";
	cout << "While exploring the Tower, you will find various *items* and *objects*. Such items will be helpful in solving puzzles. To look at an item, type 'inspect [item name]', for example 'inspect torch' will";
	cout << "briefly describe what the torch looks like and if it is lit or not. To use an item, type 'use [item name]'";
	cout << "for example 'use torch' will light the torch while 'use key' will try to use key on lock. Objects can also be moved, for example 'move vase'.";
	cout << "to see what items are around you, type 'look' and you will get an idea of what's around you including stuff you can interact with. Once you have solved the room, type 'open trapdoor' to open and descend further.";
}