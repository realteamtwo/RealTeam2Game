#ifndef ITEM
#define ITEM

#include <string>

class Item {
public:
	//CONSTRUCTORS
	
	//Default constructor
	//Included for completeness, but consider using the other constructor instead
	//Sets the name and description to "NONE"
	Item();
	//Constructor that sets name and description
	Item(std::string, std::string);


	//MUTATORS

	//Sets the item's name
	void setDisplayName(std::string);
	//Sets the item's description
	void setDescription(std::string);

	
	//ACCESSORS
	
	//Returns the item's name
	std::string getDisplayName();
	//Returns the item's description
	std::string getDescription();


	//OTHER
	
	//Checks if two items are equal (their names and descriptions both match)
	bool operator==(Item);
private:
	std::string displayName;
	std::string description;
};
#endif