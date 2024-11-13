//cpp for Level 3 (the potion room) will be where location descriptions snd interactions for the player will be
#include "Level3.h"
#include "Player.h"
#include "Item.h"


//declaring Items so they can be used in methods
Item MagicPowder;
Item SnakeVenom;
Item IceHerbs;
Item AcidPotion;

Level3::Level3() {
	//items we might encounter in level 3 not sure where to put these
	///This is the Item for magic powder which will be found in level 3 storage room
	MagicPowder.setDescription("A metallic cylinder with labeled magic powder. The sound of grains swishing happens when you move it. A warning label says do not open.");
	MagicPowder.setDisplayName("Magic Powder");
	///Magic Powder done
	///This is the Item for snake venom which will be found in level 3 storage room
	SnakeVenom.setDescription("A vial filled with murky dark liquid ");
	SnakeVenom.setDisplayName("Snake Venom");
	///Snake Venom done
	///This is the Item for Herbs which will be found in level 3 ice room
	IceHerbs.setDescription("Light blue herbs with spiky leaves. The herbs are still cold to the touch ");
	IceHerbs.setDisplayName("Herbs");
	///Herbs done
	///item for acid potion it should be made by mixing snake venom and magic powder
	AcidPotion.setDescription("A bubbling liquid made by mixing magic powder and snake venom ");
	AcidPotion.setDisplayName("Acid Potion");
	cauldronExploded = false;
}





//when player enters a room they get a description so they know what's up. The player is also informed of how to move
void Level3::displayDescription(Player& p) {
	switch (p.getLocation3()) {

		//first case and player starts here, where trapdoor is located so if else statement should occur to check locked or unlocked
	case Location3::CENTER_ROOM:

		//current description perhaps some flair for a potion room:)
		//also will be in the else once we figure out how the door unlocks in this room
		if (cauldronExploded == true)
		{
			cout << "The cauldron has exploded and revealed a path forward." << endl;
			cout << "You are in a central area with an opening in the floor. The cauldron is gone." << endl;
			cout << "Four hallways extend from this room to other areas." << endl;
		}
		else
		{
			cout << "You are in a central area with another locked trapdoor. A large cauldron in the center stands out." << endl;
		}
		cout << "Four hallways extend from this room to other areas." << endl;

		//if(have magic powder && have snake venom) { cout << you have ingredients ready to brew. Put them in the cauldron << endl;}
		//p.addItem(AcidPotion);
		//p.removeItem(SnakeVenom);
		//p.removeItem(MagicPowder);
		break;

		//put which room
	case Location3::DOWN_ROOM:
		cout << "A room full of shelves and boxes of unknown contents line the walls. Paper and clutter stretches out before you." << endl;
		cout << "Type look to look around. If you want to go back type leave. " << endl;
		break;
		// put which room it is
	case Location3::RIGHT_ROOM:
		cout << "A cold breeze chills you. You notice a thin layer of frost on the floor" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;

		break;
		//put which
	case Location3::LEFT_ROOM:
		cout << "put description :)" << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
		//put which room 
	case Location3::UP_ROOM:
		cout << "You have entered the Acid Potion Room!" << endl;
		cout << "This room is filled with mysterious markings, shelves of strange ingredients, and glowing potions." << endl;
		cout << "You see a cauldron bubbling softly in the corner." << endl;
		cout << "There are riddles on the walls, and items scattered around." << endl;
		cout << "Solve the puzzles and interact with objects to find the Acid Potion." << endl;
		cout << "Type up, down, left, or right to look around. If you want to go back type leave. " << endl;
		break;
	}
}

//for interaction based on player's input as seen in RealTeam2Game.cpp
//takes input string
//each room has interactions specific for the room so it matters which room they are in
void Level3::interact(Player& p, std::string input) {
	//based on player's current location does specific run function
	switch (p.getLocation3()) {
	//starting
	case Location3::CENTER_ROOM:
		Level3::runCenterRoom(p, input);
		break;

	case Location3::DOWN_ROOM:
		Level3::runDownRoom(p, input);
		break;

	case Location3::RIGHT_ROOM:
		Level3::runRightRoom(p, input);
		break;

	case Location3::LEFT_ROOM:
		Level3::runLeftRoom(p, input);
		break;

	case Location3::UP_ROOM:
		Level3::runUpRoom(p, input);
		break;
	}
}

void Level3::runCenterRoom(Player& p, std::string input) {
	if (input == "down") {
		cout << " you go down " << endl;
		//update location to DOWN_ROOM
		p.setLocation3(Level3::Location3::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << "You go up" << endl;
		p.setLocation3(Level3::Location3::UP_ROOM);
		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " you go left" << endl;
		p.setLocation3(Level3::Location3::LEFT_ROOM);
		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " you go right" << endl;
		p.setLocation3(Level3::Location3::RIGHT_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "leave") {
		cout << " You're In Center Room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
		//update location to RIGHT_ROOM
	}
	else if (input == "ascend")
	{
		cout << "You went back to the previous room." << endl;
		p.setLevel(2);
		//Set level back to level 2
	}
	else if (input == "descend")
	{
		if (cauldronExploded == true)
		{
			cout << "You go down through the hole to the next floor of the tower." << endl;
		}
		else
		{
			cout << "The trapdoor is locked!" << endl;
		}
	}
	else if (input == "cauldron" || input == "brew") {
		//Brewing process
		//Ask the player for the first ingredient
		Item ingredient1;
		cout << "Choose an item you have as the first potion ingredient (case sensitive), or exit to step away: " << endl;

		//List all items the player has, while also storing their names for input checking
		vector<string> playerItemNames;
		vector<Item> playerItems = p.getItems();
		for (int i = 0; i < playerItems.size(); i++) {
			cout << playerItems[i].getDisplayName() << endl;
			playerItemNames.push_back(playerItems[i].getDisplayName());
		}

		//Get the player's first choice and check that they have the item
		string ingredientRequested;
		bool ingredientValid = false;
		cin.clear();
		cin.ignore();
		getline(cin, ingredientRequested);
		if (ingredientRequested == "exit") {
			cout << "You stepped away from the cauldron." << endl;
			return;
		}
		for (int i = 0; i < playerItemNames.size(); i++) {
			if (ingredientRequested == playerItemNames[i]) {
				ingredientValid = true;
				ingredient1 = playerItems[i];
			}
		}
		if (!ingredientValid) {
			cout << "You don't have that item!" << endl;
			return;
		}

		//Ask for the second ingredient and check for it too
		Item ingredient2;
		ingredientValid = false;
		cout << "Choose a second ingredient (case sensitive), or exit to take back the first ingredient: " << endl;
		cin.clear();
		string ingredientRequested2;
		getline(cin, ingredientRequested2);
		if (ingredientRequested2 == "exit") {
			cout << "You stepped away from the cauldron." << endl;
			return;
		}
		else if (ingredientRequested2 == ingredient1.getDisplayName()) {
			cout << "You already used that item!" << endl;
			return;
		}
		for (int i = 0; i < playerItemNames.size(); i++) {
			if (ingredientRequested2 == playerItemNames[i]) {
				ingredientValid = true;
				ingredient2 = playerItems[i];
			}
		}
		if (!ingredientValid) {
			cout << "You don't have that item!" << endl;
			return;
		}

		//Potion recipes! Check if the input items form a valid recipe.
		//When adding a new recipe, check both combinations of ingredients here.(example provided)
		if (
			(ingredient1 == MagicPowder && ingredient2 == SnakeVenom)
			|| (ingredient1 == SnakeVenom && ingredient2 == MagicPowder)
			// || (ingredient1 == YourFirstIngredient && ingredient2 == YourSecondIngredient)
			// || (ingredient1 == YourSecondIngredient && ingredient2 == YourFirstIngredient)
		)
		{
			Item brewedItem;

			//Acid potion recipe, use as a template for other recipes
			if ((ingredient1 == MagicPowder && ingredient2 == SnakeVenom) || (ingredient1 == SnakeVenom && ingredient2 == MagicPowder)) {
				brewedItem = AcidPotion;
			}

			if (p.hasItem(brewedItem)) {
				cout << "You already have that potion!" << endl;
			}
			else {
				cout << "You brewed: " << brewedItem.getDisplayName() << ", " << brewedItem.getDescription() << endl;
				p.removeItem(ingredient1.getDisplayName());
				p.removeItem(ingredient2.getDisplayName());
				p.addItem(brewedItem);
			}
		}
		
	}
	//need unlocking here
	// Add Stop Watch Code for Level 3
}

//this is the room the player can enter by going to the right from center room, the ice room
//now when it gets input from player it will do stuff
//this is where the items snake venom and magic powder will be gotten
void Level3::runDownRoom(Player& p, std::string input) {
	//prompt
	//check if 'input is right' for what it is gotten from
	string answer;
	cout << "Perhaps there is something useful here?" << endl;
	//based on input of player different things can happen (for information check player files and main)
	if (input == "look") {
		cout << "Some of the boxes to your left and right stand out. " << endl;
	}
	//theoretically we would want this to be pressed after look but no reason they shouldn't be able to
	else if (input == "left") {
		cout << "There is an open chest. Inside there is what looks like the fossilized remains of a snake, and a vial of liquid" << endl;
		cout << "Type left, right, look, or pickup to interact. When you want to leave type leave." << endl;
	}
	else if (input == "right") {
		cout << "Amongst several piles of paper is a metallic cylinder. A warning label reads 'Do Not Open: Magic Powder'" << endl;
		cout << "Pickup? (Y/N): ";
		//this is to get the yes or no answer to this question wanted to keep it separate from input
		cin >> answer;
		if (answer == "Y") {
			if (p.hasItem(MagicPowder)) {
				cout << "You already have this item!" << endl;
			}
			else {
				//add item to inventory
				p.addItem(MagicPowder);
				cout << "You picked up Magic Powder" << endl;
			}
		}
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
	}
	else if (input == "pickup") {
		cout << "which one? " << endl;
	}
	else if (input == "vial" || input == "venom") {
		if (p.hasItem(SnakeVenom)) {
			cout << "You already have this item!" << endl;
		}
		else {
			cout << "You picked up Snake Venom" << endl;
			//adding item to inventory
			p.addItem(SnakeVenom);
		}
	}
	else if (input == "fossil" || input == "remains") {
		cout << "You attempt to pick it up but it starts to break. Oops. " << endl;
	}
		
}
//this is the room the player can enter by going to the right from center room, the ice room
//now when it gets input from player it will do stuff
void Level3::runRightRoom(Player& p, std::string input) {

	cout << "A chill runs through you. " << endl;
	if (input == "right") {
		cout << "blue plants are sprouting in pots of frozen earth. " << endl;
		p.addItem(IceHerbs);
	}
	else if (input == "left") {
		cout << "You see a red valve handle. Trying to move it does nothing as the cold metal refuses to budge" << endl;
	}
	else if (input == "down") {
		cout << "A knozzle that still works is attached to the wall. " << endl;
	}
	else if (input == "up") {
		cout << "Several glass jars line the wall filled with rotting plants. " << endl;
	}
	else if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
	}
}
//this is the room the player can enter by going to the up from center room, the ACID POTION room
void Level3::runUpRoom(Player& p, std::string input) {
	// handles the interaction when the player moves up to the riddle wall.
	if (input == "up") {
		cout << "You approach the wall with the riddle. The symbols glow faintly, drawing your attention to the carved words:" << endl;
		cout << "'I am something that burns, but I�m not fire. I am a liquid that can melt steel.' " << endl;
		cout << "What is your answer?" << endl;
		string answer;
		cin >> answer;
		
		//checks if the user answers the riddle correctly
		if (answer == "acid" || answer == "Acid") {
			cout << "Correct! A hidden compartment opens in the wall, revealing a bottle labeled 'Acid Potion'!" << endl;
			//Add item to inventory
			p.addItem(AcidPotion);
		}
		else {
			cout << "That's not the correct answer. The riddle remains unsolved." << endl;
		}
	}
	// handles the interaction when the player moves down to the door to the Ice Room.
	else if (input == "down") {
		cout << "You turn to face the door leading to the Ice Room. The door is reinforced with a strange icy material." << endl;
		cout << "It won't budge without something strong enough to melt the ice." << endl;
	}
	// handles the interaction when the player moves left to the shelves of ingredients.
	else if (input == "left") {
		cout << "You move to the left wall. Shelves stacked with dusty bottles and peculiar artifacts line the surface." << endl;
		cout << "One jar stands out, glowing faintly, but it�s sealed tightly. There doesn�t seem to be anything else useful here." << endl;
	}//handles the interaction when the user moves right to the alchemical table.
	else if (input == "right") {
		cout << "You approach a small alchemical table on the right. Strange instruments and scattered notes cover its surface." << endl;
		cout << "A torn piece of parchment catches your eye. It reads: 'What burns but is not fire can open the way forward.' " << endl;
	}
	// displaying the description of the room, when the player inputs look 
	else if (input == "look") {
		cout << "The room is dimly lit, with bubbling sounds coming from a cauldron in the corner." << endl;
		cout << "The walls are covered in glowing symbols. There�s a riddle inscribed on the wall to the north." << endl;
		cout << "Shelves of ingredients line the west, while an alchemical table occupies the east." << endl;
		cout << "The door to the Ice Room stands to the south, locked tight with frost." << endl;
	}
	// handles leaving the ACID POTION room and return to the center room.
	else if (input == "leave") {
		cout << "You step away from the Acid Potion Room and return to the center room." << endl;
		p.setLocation3(Location3::CENTER_ROOM);
	}
	else {
	cout<<" Try another command"<< endl;
	}

}
void Level3::runLeftRoom(Player& p, std::string input) {

}