//cpp for Level 3 (the potion room) will be where location descriptions snd interactions for the player will be
#include "Level3.h"
#include "Player.h"
#include "Item.h"

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>


//declaring Items so they can be used in methods
Item MagicPowder;
Item SnakeVenom;
Item IceHerbs;
Item AcidPotion;
Item GrowthPotion;
Item VolatileEssence;
Item Trowel;

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
	//Growth Potion
	GrowthPotion.setDescription("A strange liquid that seems to make plants grow quickly");
	GrowthPotion.setDisplayName("Growth Potion");
	//Volatile Essence
	VolatileEssence.setDescription("A box with many warnings on it, containing a bright red powder.");
	VolatileEssence.setDisplayName("Volatile Essence");
	Trowel.setDescription("A small trowel with magic runes engraved on it");
	Trowel.setDisplayName("Trowel");

	cauldronExploded = false;
	plantGrown = false;
}

string inspectDescription3(string itemName) {
	if (itemName == "magic powder") {
		return MagicPowder.getDescription();
	}
	else if (itemName == "snake venom") {
		return SnakeVenom.getDescription();
	}
	else if (itemName == "ice herbs") {
		return IceHerbs.getDescription();
	}
	else if (itemName == "acid potion") {
		return AcidPotion.getDescription();
	}
	else if (itemName == "growth potion") {
		return GrowthPotion.getDescription();
	}
	else if (itemName == "volatile essence") {
		return VolatileEssence.getDescription();
	}
}



//when player enters a room they get a description so they know what's up. The player is also informed of how to move
void Level3::displayDescription(Player& p) {
	switch (p.getLocation3()) {

		//first case and player starts here, where trapdoor is located so if else statement should occur to check locked or unlocked
	case Location3::CENTER_ROOM:

		//current description perhaps some flair for a potion room:)
		//also will be in the else once we figure out how the door unlocks in this room
		if (cauldronExploded == true) //Checks if the leave condition has been met and prints different text
		{
			if (doorunlocked == false)
			{
				// How much time has passed in the game overall since beating level 2
				cout << "\n" << "Level #3 has been completed in: ";
				L3Time.printDiffTime();
				doorunlocked = true;
			}
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

		cout << "Type 'look' to see. If you want to go back type leave. " << endl;
		break;
		//put which room 
	case Location3::UP_ROOM:
		
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
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     | P |     " << endl;
		cout << " you go down " << endl;
		//update location to DOWN_ROOM
		p.setLocation3(Level3::Location3::DOWN_ROOM);
	}
	else if (input == "up") {
		cout << " current location:" << endl;
		cout << "     | P |           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << " you go up" << endl;
		cout << "There is nothing" << endl;
	p.setLocation3(Level3::Location3::CENTER_ROOM);

		//update location to UP_ROOM
	}
	else if (input == "left") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "| P |     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << " you go left" << endl;
	p.setLocation3(Level3::Location3::LEFT_ROOM);

		//update location to LEFT_ROOM
	}
	else if (input == "right") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     | P |" << endl;
		cout << "     |///|     " << endl;
		if (!iceRoomDoorOpen) {
			if (p.hasItem(AcidPotion))
			{
				cout << " You have something in your inventory which you can use to unlock this door." << endl;
				cin >> input;
				if (input == "acid" || input == "Acid Potion")
				{
					cout << " You used the acid to melt the ice, which was blocking you from entering the ice room." << endl;
					cout << " The door is now open." << endl;
					cout << "A chill runs through you. " << endl;
					p.removeItem("Acid Potion");
					iceRoomDoorOpen = true;

				}
				else
				{
					cout << " This is not an appropriate item, Try Again" << endl;
					return;
				}
			}
			else
			{
				cout << " You can't go to the ice room, the door is locked. You need something to unlock it." << endl;
				return;
			}
		}
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
	//Checks if leave condition has been met to be able to descend to the next floor
	else if (input == "descend")
	{
		if (cauldronExploded == true)
		{
			cout << "You go down through the hole to the next floor of the tower." << endl;
			p.setLevel(4);
		}
		else
		{
			cout << "The trapdoor is locked!" << endl;
		}
	}
	else if (input == "cauldron" || input == "brew") {
		if (cauldronExploded) {
			cout << "The cauldron is gone." << endl;
		}
		else {
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
			brewPotion(p, ingredient1, ingredient2);
		}
	}
	//for inspecting items in inventory
	else if (input == "inspect") {
		//we want to compare the name they put in to the name of the item
		string itemName;
		cout << "Which item?: " << endl;
		cin >> itemName;
		inspectDescription3(itemName);
	}
	//need unlocking here
	// Add Stop Watch Code for Level 3

	
}

//Brew a potion given two items
void Level3::brewPotion(Player& p, Item ingredient1, Item ingredient2) {
	if (ingredient1 == VolatileEssence || ingredient2 == VolatileEssence) {
		//Special case for brewing with volatile essence. This blows up the cauldron
		p.removeItem("Volatile Essence");
		cout << "As you mix the ingredients, the volatile essence causes the cauldron to bubble and shake until sudddenly, it explodes!" << endl;
		cout << "All that remains is a hole where the cauldron once stood. Now you can descend to the next floor." << endl;
		cauldronExploded = true;
	}
	else if (
		(ingredient1 == MagicPowder && ingredient2 == SnakeVenom)
		|| (ingredient1 == SnakeVenom && ingredient2 == MagicPowder)
		//Special case for jar of earthworms, use the name instead of the item since it's from another room
		|| (ingredient1.getDisplayName() == "Worms" && ingredient2 == IceHerbs)
		|| (ingredient1 == IceHerbs && ingredient2.getDisplayName() == "Worms")
		// || (ingredient1 == YourFirstIngredient && ingredient2 == YourSecondIngredient)
		// || (ingredient1 == YourSecondIngredient && ingredient2 == YourFirstIngredient)
		)
	{
		Item brewedItem;

		//Acid potion recipe, use as a template for other recipes
		if ((ingredient1 == MagicPowder && ingredient2 == SnakeVenom) || (ingredient1 == SnakeVenom && ingredient2 == MagicPowder)) {
			brewedItem = AcidPotion;
		}
		else if ((ingredient1.getDisplayName() == "Worms" && ingredient2 == IceHerbs) || (ingredient1 == IceHerbs && ingredient2.getDisplayName() == "Worms")) {
			brewedItem = GrowthPotion;
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
	else {
		cout << "You put the items into the cauldron, but nothing magical seems to happen." << endl;
		cout << "Maybe try a different recipe?" << endl;
	}
}

//this is the room the player can enter by going to the right from center room, the ice room
//now when it gets input from player it will do stuff
//this is where the items snake venom and magic powder will be gotten
void Level3::runDownRoom(Player& p, std::string input) {
	//prompt
	//check if 'input is right' for what it is gotten from
	string answer;
	cout << "Perhaps there is something useful here?" << endl;
	cout << "Type up, left, down, right, look, or pickup to interact. When you want to leave type leave." << endl;
	//based on input of player different things can happen (for information check player files and main)
	if (input == "look") {
		cout << "Some of the boxes to your left and right stand out." << endl;
		cout << "There is a bookshelf on the upwards wall." << endl;
		if (!plantGrown) {
			cout << "There is also another box on a high shelf on the downwards wall, far out of reach. There is a small plant below the shelf." << endl;
		}
	}
	else if (input == "up") { //Hint for the alchemist's first riddle
		cout << "There is a bookshelf on the wall near the door. One of them, a book about alchemy, stands out." << endl;
		cout << "The text talks about how transmutation involves moving letters around in a word." << endl;
	}
	//theoretically we would want this to be pressed after look but no reason they shouldn't be able to
	else if (input == "left") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "| P |     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << "There is an open chest. Inside there is what looks like the fossilized remains of a snake, and a VIAL of liquid" << endl;
	}
	else if (input == "right") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     | P |" << endl;
		cout << "     |///|     " << endl;
		cout << "Amongst several piles of paper is a metallic cylinder. A warning label reads 'Do Not Open: Magic Powder'" << endl;
		cout << "Pickup? (Y/N): ";
		//this is to get the yes or no answer to this question wanted to keep it separate from input
		cin >> answer;
		if (answer == "Y"|| answer=="y") {
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
	else if (input == "down") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     | P |     " << endl;
		if (plantGrown) {
			cout << "This section of the room is mossy and downtrodden. A large stalk grows from the floor to the ceiling." << endl;
		}
		else {
			cout << "This section of the room is mossy and downtrodden. A single plant is sprouting out of the floor. There is also a small crate on a high shelf far out of reach." << endl;
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
	else if (input == "grow" || input == "growth" || input == "potion") { //Growth potion usage
		if (p.hasItem(GrowthPotion) && !plantGrown) {
			plantGrown = true;
			p.removeItem("Growth Potion");
			cout << "You pour the growth potion onto the plant. Within seconds, it turns into a huge vine! You climb it to reach the high shelf and grab the box, which has several warnings on it." << endl;
			cout << "Obtained Volatile Essence." << endl;
			p.addItem(VolatileEssence);
		}
	}
	else if (input == "inspect") {
		//we want to compare the name they put in to the name of the item
		string itemName;
		cout << "Which item?: " << endl;
		cin >> itemName;
		inspectDescription3(itemName);
	}
		
}
//this is the room the player can enter by going to the right from center room, the ice room
//now when it gets input from player it will do stuff
void Level3::runRightRoom(Player& p, std::string input) {
	if (input == "right") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     | P |" << endl;
		cout << "     |///|     " << endl;
		cout << "blue plants are sprouting in pots of frozen earth. " << endl;
		if (p.hasItem(Trowel)) {
			cout << "You picked up Herbs with the Trowel! " << endl;
			p.addItem(IceHerbs);
		}
		else {
			cout << "If only you had something to help you get them out of the dirt..." << endl;
		}
	}
	else if (input == "left") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "| P |     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << "You see a red valve handle. Trying to move it does nothing as the cold metal refuses to budge" << endl;
	}
	else if (input == "down") {
		cout << " current location:" << endl;
		cout << "     |///|           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     | P |     " << endl;
		cout << "A knozzle that still works is attached to the wall. " << endl;
	}
	else if (input == "up") {
		cout << " current location:" << endl;
		cout << "     | P |           " << endl;
		cout << "|///|     |///|" << endl;
		cout << "     |///|     " << endl;
		cout << "Several glass jars line the wall filled with rotting plants. " << endl;
	}

	if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
	}

	if (input == "inspect") {
		//we want to compare the name they put in to the name of the item
		string itemName;
		cout << "Which item?: " << endl;
		cin >> itemName;
		inspectDescription3(itemName);
	}
	
}
//this is the room the player can enter by going to the up from center room, the ACID POTION room
void Level3::runUpRoom(Player& p, std::string input) {
	cout << "There is nothing" << endl;
	p.setLocation3(Level3::Location3::CENTER_ROOM);

	// handles the interaction when the player moves up to the riddle wall.
	/*if (input == "up") {
		cout << "You approach the wall with the riddle. The symbols glow faintly, drawing your attention to the carved words:" << endl;
		cout << "'I am something that burns, but I'm not fire. I am a liquid that can melt steel.' " << endl;
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
		cout << "One jar stands out, glowing faintly, but it's sealed tightly. There doesn't seem to be anything else useful here." << endl;
	}//handles the interaction when the user moves right to the alchemical table.
	else if (input == "right") {
		cout << "You approach a small alchemical table on the right. Strange instruments and scattered notes cover its surface." << endl;
		cout << "A torn piece of parchment catches your eye. It reads: 'What burns but is not fire can open the way forward.' " << endl;
	}
	// displaying the description of the room, when the player inputs look 
	else if (input == "look") {
		cout << "The room is dimly lit, with bubbling sounds coming from a cauldron in the corner." << endl;
		cout << "The walls are covered in glowing symbols. There's a riddle inscribed on the wall to the north." << endl;
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
	}*/

}
//for hangman in left room
bool hasWon = false;
class HangmanGame {
public:
	//constructor, initializes
	HangmanGame()
	{
		srand(static_cast<unsigned int>(time(nullptr)));
		secretWord = "trowel"; 
		//secretWord.length() could be used instead of six but since the word is always trowel we can use 6
		currentWord = string(6, '_');
		attemptsLeft = 6;
	}

	// function to start the game.
	void play()
	{
		cout << "You find in this room a strange image made with light magic" << endl;
		cout << "HANGMAN" << endl;
		cout << "   _____" << endl;
		cout << "  |     |" << endl;
		cout << "  |      " << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;
		cout << "  |" << endl;

		cout << "You have " << attemptsLeft << " attempts to guess the word." << endl;

		// the main game loop which will go on till the
		// attempts are left or the game is won.
		while (attemptsLeft > 0) {
			displayGameInfo();
			char guess;
			cout << "Guess a letter: ";
			cin >> guess;

			if (isalpha(guess)) {
				guess = tolower(guess);
				if (alreadyGuessed(guess)) {
					cout << "You've already guessed that letter."
						<< endl;
				}
				else {
					bool correctGuess = updateCurrentWord(guess);
					// if the guess is correct, we will
					// update the word and check if the word
					// is completely guessed or not
					if (correctGuess) {
						cout << "Good guess!" << endl;
						drawHangman(attemptsLeft);
						// if the word is completely
						// guessed.
						if (currentWord == secretWord) {
							displayGameInfo();
							cout << "Congratulations! You guessed the word: trowel. The light flickers away."  << endl;
							hasWon = true;
							return;
						}
					}
					else {
						cout << "Incorrect guess." << endl;
						attemptsLeft--;
						drawHangman(attemptsLeft);
					}
				}
			}
			else {
				cout << "Please enter a valid letter."
					<< endl;
			}
		}

		if (attemptsLeft == 0) {
			displayGameInfo();
			cout << "You've run out of attempts." << endl;
			cout << "restarting game" << endl;
			attemptsLeft = 6;
			currentWord = string(secretWord.length(), '_');
		}
	}

private:
	string secretWord;
	string currentWord;
	int attemptsLeft;
	vector<char> guessedLetters;


	// checking if the word is already guessed
	bool alreadyGuessed(char letter)
	{
		return find(guessedLetters.begin(),
			guessedLetters.end(), letter)
			!= guessedLetters.end();
	}

	// updating the word after correct guess
	bool updateCurrentWord(char letter)
	{
		bool correctGuess = false;
		//could use secretWord.length() but the length is 6
		for (int i = 0; i < 6; i++) {
			if (secretWord[i] == letter) {
				currentWord[i] = letter;
				correctGuess = true;
			}
		}
		guessedLetters.push_back(letter);
		return correctGuess;
	}

	// function to provide the info at particular point in
	// the game
	void displayGameInfo()
	{
		cout << "Word: " << currentWord << endl;
		cout << "Attempts left: " << attemptsLeft << endl;
		cout << "Guessed letters: ";
		for (char letter : guessedLetters) {
			cout << letter << " ";
		}
		cout << endl;
	}

	// function to progressively draw the hangman
	void drawHangman(int attemptsLeft)
	{
		// Add your hangman drawing logic here
		// For simplicity, you can print a static hangman
		// ASCII art Modify this function to display the
		// hangman as you like
		if (attemptsLeft == 6) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |      " << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 5) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 4) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |     |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 3) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |    /|" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 2) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |    /|\\" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 1) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |    /|\\" << endl;
			cout << "  |    /" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
		else if (attemptsLeft == 0) {
			cout << "   _____" << endl;
			cout << "  |     |" << endl;
			cout << "  |     O" << endl;
			cout << "  |    /|\\" << endl;
			cout << "  |    / \\" << endl;
			cout << "  |" << endl;
			cout << "  |" << endl;
		}
	}
};


void Level3::runLeftRoom(Player& p, std::string input) {
	if (p.hasItem(Trowel)) {
		cout << "You have already solved the room there is nothing left here" << endl;
	}
	else {
		while (hasWon != true) {
			HangmanGame game;
			game.play();
		}
		cout << "You received a trowel! " << endl;
		p.addItem(Trowel);
	}
	cout << "type leave to leave" << endl;

	if (input == "leave") {
		cout << "You are in center room" << endl;
		p.setLocation3(Level3::Location3::CENTER_ROOM);
	}
}