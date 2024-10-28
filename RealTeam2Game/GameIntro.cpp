#include <iostream>
#include "GameIntro.h"

using namespace std;

void Backstory() {
	
	
	cout << "In a realm where magic intertwines with reality, you play as(Player), a talented yet impulsive young mage known for having great curiosityand a knack for experimentation.\n";
	cout << "After years of studying ancient tomes, (Player)finally uncovers a long - forgotten teleportation spell that promises to reveal hidden truths of the world.\n";
	cout << "Eager to seek newfound knowledge, (Player)prepares the ritual in the mage tower, envisioning a journey to a legendary library rumored to contain secrets of unparalleled power.However, as(Player) recites the incantation, a sudden surge of dark energy ripples through the air, causing the spell to twistand warp.\n";
	cout << "Instead of the library of secrets, (Player)finds themselves in an unfamiliar, dimly lit room—a chamber deep within the lair of(Evil Alchemist), a notorious alchemist known for his dangerous experimentsand mastery of dark magic.\n";
	cout << "The air is thick with the scent of burnt herbs and ominous energy, and the walls are lined with arcane symbols pulsating with an eerie glow.Realizing(Blank) has unwittingly stumbled into(Evil Alchemist) tower, (Blank)heart races.\n";
	cout << "Legends speak of the alchemists twisted experiments, using unwitting subjects to fuel his ambition for immortality.\n";
	cout << "Determined to escape, (Player)discovers that the tower is a labyrinth of shifting rooms and realms with enchanted traps, each one being a reflection of(Evil Alchemist) twisted mindand insatiable thirst for knowledge.\n";
	cout << "They could either be as simple as matching words on a desk or as hard as deciphering a mysterious language.As(Player) navigates this perilous environment, they must solve intricate puzzles, each designed to test her intellectand magical prowess.Along the way, they encounter remnants of(Evil Alchemist) past victims—spirits trapped in the tower, their whispers guiding or misdirecting her.\n";
	cout << "To escape, (Player)must harness the very magic that brought them here, learning to bend the rules of her own spells to manipulate the tower’s layout.With every level she descends, the challenges become more daunting,\n";
	cout << "revealing more about(Evil Alchemist) dark experiments and his ultimate goal : to unlock the secrets of life and death.(Player)journey is not just a race against time to escape; it becomes a quest to confront her own fears, unravel the truth behind the alchemists madness, and ultimately challenge the very forces that have ensnared them.Can(Player) outwit the tower’s defenses, confront(Evil Alchemist) dark legacy, and find their way back home before it’s too late ? The fate of the world—and perhaps their very soul—hangs in the balance." << endl << endl;
}

void Controls() {
	cout << "To descend the Tower, you must open the trapdoor in the middle of each room," << "which will often be locked in some way. The method to do so is hidden in the room. Investigate, solve puzzles and use items." << endl;
	cout << "While exploring the Tower, you will find various *items* and *objects*. Such items will be helpful in solving puzzles. To look at an item, type 'inspect [item name]', for example 'inspect torch' will" << endl;
	cout << "briefly describe what the torch looks like and if it is lit or not. To use an item, type 'use [item name]'" << endl;
	cout << "for example 'use torch' will light the torch while 'use key' will try to use key on lock. Objects can also be moved, for example 'move vase'." << endl;
	cout << "to see what items are around you, type 'look' and you will get an idea of what's around you including stuff you can interact with. Once you have solved the room, type 'open trapdoor' to open and descend further." << endl;
}
