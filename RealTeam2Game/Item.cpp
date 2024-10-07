#include <string>
#include "Item.h"

//Constructors
Item::Item() {
	displayName = "NONE";
	description = "NONE";
}
Item::Item(std::string n, std::string d) {
	displayName = n;
	description = d;
}

//Mutators
void Item::setDisplayName(std::string n) {
	displayName = n;
}
void Item::setDescription(std::string d) {
	description = d;
}

//Accessors
std::string Item::getDisplayName() {
	return displayName;
}
std::string Item::getDescription() {
	return description;
}

std::string displayName;
std::string description;