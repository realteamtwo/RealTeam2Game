#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include <vector>
#include "../RealTeam2Game/Player.cpp"
#include "../RealTeam2Game/Item.cpp"
#include "../RealTeam2Game/Level2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RealTeam2Test
{
	TEST_CLASS(RealTeam2Test)
	{
	public:
		Player player;
		TEST_METHOD(VerifyPlayerConstructor)
		{
			Logger::WriteMessage("Verifying player initially configured for level 1\n");
			Assert::AreEqual(player.getLevel(), 1);

			Logger::WriteMessage("Verifying player location set to level 2 Center Room?\n");
			Level2::Location expectedLocation = Level2::Location::CENTER_ROOM;
			Level2::Location actualLocation = player.getLocation();
			Assert::AreEqual(static_cast<int>(expectedLocation), static_cast<int>(actualLocation), L"getLocation() did not return the expected CENTER_ROOM");
		}

		/**
		 * Item class has two constructors - one w/o arguments setts the item name & description to "NONE",
		 *    one w/ two arguments sets the item name & description as specified
		 * Class has two getters & setters, one for the DisplayName, other for the Description
		 * Test belows creates two items and then verifies the getters return the correct details
		 * 
		 */
		TEST_METHOD(VerifyItemClass) {
			Logger::WriteMessage("Create two items - Cat & Dog\n");
			Item cat;
			cat.setDisplayName("CAt");
			cat.setDescription("hairy thing, also with four legs");
			Item dog("Dog", "furry thing with four legs");

			Logger::WriteMessage("Verify CAt returned correctly\n");
			cat.setDisplayName("CAt");
			cat.setDescription("hairy thing, also with four legs");
			std::string expected = "CAt";
			std::string actual = cat.getDisplayName();
			Assert::AreEqual(expected, actual);

			Logger::WriteMessage("Verify Dog returned correctly\n");
			expected = "Dog";
			actual = dog.getDisplayName();
			Assert::AreEqual(expected, actual);

		}

		/**
		 * Players can have items on their personage.
		 * The Player class implements the ability to addItem(), removeItem() and vector<Item> getItems().
		 * Verify proper behavior by adding and removing items in various orders
		 * 
		 * addItem() - adds the instance, a single instance can be added multiple times
		 *    there is no error return - so passing a garbage instance is placed in the player inventory
		 * removeItem(string) - deletes the item with the displayName in the parameter
		 *     if multiple items with the same name exist in the players inventory, all will be deleted
		 *     if the item doesn't exist, no error returned, and nothing should be deleted
		 * getItems() - returns all of the items in the player's inventory, even duplicates
		 * 
		 * Note - not available at this time is the ability to check if the person has a particular item in their inventory
		 */

		TEST_METHOD(PlayerItemManagement) {
			// std::string catItemNames(vector<Item>);
			Logger::WriteMessage("// Testing player item management\n");
			Item cat("cat", "hairy thing");
			Item dog("dog", "furry thing");
			Item fox("fox", "wild thing");
			Player player;
			player.addItem(cat);
			player.addItem(dog);
			player.addItem(fox);
			std::string inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// Removing cat & adding it back in
			Logger::WriteMessage("// Removing cat\n");
			player.removeItem("cat");
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());
			Logger::WriteMessage("// --Adding cat back in\n");
			player.addItem(cat);
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// Remove cat again
			Logger::WriteMessage("// Removing cat again\n");
			player.removeItem("cat");
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// Remove hippo - which doesn't exist
			Logger::WriteMessage("// Remove a non-existent hippo!\n");
			player.removeItem("hippo");
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// now let's play with duplicates - add a couple of foxes and another dog and then remove fox
			Logger::WriteMessage("// Add two foxes and a couple of dogs\n");
			player.addItem(fox);
			player.addItem(fox);
			player.addItem(dog);
			player.addItem(dog);
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());
			Logger::WriteMessage("Now remove the dogs\n");
			player.removeItem("dog");
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// lastly let's go down to an empty list - ie remove the foxes, and add back in a cat
			Logger::WriteMessage("// Remove the foxes, so we get an empty list and add back in a cat\n"); 
			player.removeItem("fox");
			player.addItem(cat);
			inventory = catItemNames(player.getItems());
			Logger::WriteMessage(inventory.c_str());

			// try creating a null item and see what happens
			// Logger::WriteMessage("// Create a null item\n");
			// Item* nullItemPointer = nullptr;
			// player.addItem(*nullItemPointer);
			// inventory = catItemNames(player.getItems());
			// Logger::WriteMessage(inventory.c_str());
		}

		//Test the player's location in Level2
		//Enters and leaves each room and verifies the player's location is correct after each step
		TEST_METHOD(PlayerLocationTest) {
			Logger::WriteMessage("// Testing player's location in Level2");
			Level2 level;
			Player player;
			Level2::Location expected;
			Level2::Location actual;
			player.setLevel(2);
			
			Logger::WriteMessage("// Try to leave the center room (this shouldn't do anything)");
			level.interact(player, "leave");
			expected = Level2::Location::CENTER_ROOM;
			actual = player.getLocation();
			Assert::IsTrue(expected == actual);

			Logger::WriteMessage("// Make sure each direction sends the player to the appropriate room");
			Logger::WriteMessage("// Also make sure leaving each room returns the player to the center");
			Logger::WriteMessage("// Exception: Player cannot leave the fire room");

			std::string directionNames[4] = { "up", "down", "left", "right" };
			Level2::Location directionLocations[4] = {
				Level2::Location::UP_ROOM,
				Level2::Location::DOWN_ROOM,
				Level2::Location::LEFT_ROOM,
				Level2::Location::RIGHT_ROOM
			};

			for (int i = 0; i < 4; i++) {
				level.interact(player, directionNames[i]);
				expected = directionLocations[i];
				actual = player.getLocation();
				Assert::IsTrue(expected == actual);

				level.interact(player, "leave");
				if (directionNames[i] == "right") { //Special case since you can't leave the fire room
					expected = Level2::Location::RIGHT_ROOM;
				}
				else {
					expected = Level2::Location::CENTER_ROOM;
				}
				actual = player.getLocation();
				Assert::IsTrue(expected == actual);
			}
		}

		//Make sure Level 2 is beatable!
		//Artificially marks the fire room as beaten, then uses the input sequence:
		//up, earth, leave, down, air, leave, left, water, leave, descend
		TEST_METHOD(Level2CompletionTest) {
			Logger::WriteMessage("// Make sure level 2 can be completed");
			Level2 level;
			level.fireSolved = true;
			Player player;
			player.setLevel(2);
			const int INPUT_COUNT = 10;

			std::string inputSequence[INPUT_COUNT] = {
				"up", "earth", "leave", "down", "air",
				"leave", "left", "water", "leave", "descend"
			};

			for (int i = 0; i < INPUT_COUNT; i++) {
				level.interact(player, inputSequence[i]);
			}

			int expected = 3;
			int actual = player.getLevel();
			Assert::IsTrue(expected == actual);
		}

		std::string catItemNames(vector<Item> itemList) {
			std::string catString = "+";
			for (int iterator = 0; iterator < itemList.size(); iterator++) {
				catString = catString + itemList[iterator].getDisplayName() + " ";
			}
			catString = catString += "\n";
			return catString;
		}
	};

}
