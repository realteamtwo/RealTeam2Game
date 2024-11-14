#include <iostream>
#include "GameIntro.h"

using namespace std;

void Backstory() {
	
	
	cout << "In a realm where magic intertwines with reality, you are a talented yet impulsive young mage known for having great curiosity and a knack for experimentation.\n";
	cout << "After years of studying ancient tomes, you finally uncover a long - forgotten teleportation spell that promises to reveal hidden truths of the world.\n";
	cout << "Eager to seek newfound knowledge, you prepare the ritual in the mage tower, envisioning a journey to a legendary library rumored to contain secrets of unparalleled power.\n";
	cout << "However, as you recite the incantation, a sudden surge of dark energy ripples through the air, causing the spell to twist and warp. Instead of the library of secrets, you find\n";
	cout << "yourself in an unfamiliar, dimly lit room: a chamber deep within the lair of an Evil Alchemist, a notorious alchemist known for his dangerous experiments and mastery of dark magic.\n";
	cout << "The air is thick with the scent of burnt herbs and ominous energy, and the walls are lined with arcane symbols pulsating with an eerie glow. Realizing you have unwittingly stumbled\n";
	cout << "into the Evil Alchemist's tower, your heart races. Legends speak of the alchemist's twisted experiments, using unwitting subjects to fuel his ambition for immortality. Determined to escape,\n";
	cout << "you discover that the tower is a labyrinth of shifting rooms and realms with enchanted traps, each one being a reflection of the Evil Alchemist's twisted mind and insatiable thirst for knowledge.\n";
	cout << "They could either be as simple as matching words on a desk or as hard as deciphering a mysterious language. As you navigate this perilous environment, you must solve intricate puzzles,\n";
	cout << "each designed to test your intellect and magical prowess. Along the way, you encounter remnants of the Evil Alchemist's past victims: spirits trapped in the tower, their whispers guiding or misdirecting you.\n";
	cout << "To escape, you must harness the very magic that brought you here, learning to bend the rules of your own spells to manipulate the tower layout. With every level, the challenges become more daunting,\n";
	cout << "revealing more about the Evil Alchemist's dark experiments and his ultimate goal: to unlock the secrets of life and death. Your journey is not just a race against time to escape.\n";
	cout << "It becomes a quest to confront your own fears, unravel the truth behind the alchemist's madness, and ultimately challenge the very forces that have ensnared you.\n";
	cout << "Can you outwit the tower defenses, confront the Evil Alchemist's dark legacy, and find your way back home before it is too late? The fate of the world, and perhaps your very soul, hangs in the balance." << endl << endl;
}

void Controls() {
	cout << "To descend the Tower, you must open the trapdoor in the middle of each room," << " which will often be locked in some way. The method to do so is hidden in the room. Investigate, solve puzzles and use items." << endl;
	cout << "While exploring the Tower, you will find various *items* and *objects*. Such items will be helpful in solving puzzles. To look at an item, type 'inspect [item name]', for example 'inspect torch' will" << endl;
	cout << "briefly describe what the torch looks like and if it is lit or not. To use an item, type 'use [item name]'" << endl;
	cout << "for example 'use torch' will light the torch while 'use key' will try to use key on lock. Objects can also be moved, for example 'move vase'." << endl;
	cout << "to see what items are around you, type 'look' and you will get an idea of what's around you including stuff you can interact with. Once you have solved the room, type 'descend' to open and descend further." << endl << endl;
}
void clearScreen()
{
	cout << "\033[2J\033[1;1H";
}