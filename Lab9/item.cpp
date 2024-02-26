#include <string>
#include "item.h"

// Item class implementation

// Constructor: Initializes an Item with a given name.
Item::Item(const std::string& item_name) : m_name(item_name) {}

// Getter function: Returns the name of the Item.
std::string Item::getName() {
    return m_name;
}

// Equality check: Checks if the current Item is equal to another Item.
bool Item::isEqual(Item other_item) {
    // Compare the names of the current item and the other item
    return m_name == other_item.m_name;
}
