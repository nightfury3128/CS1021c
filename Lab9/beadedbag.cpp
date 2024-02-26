#include <algorithm>
#include "beadedbag.h"
#include "item.h"
#include <vector>

// BeadedBag class implementation

// Inserts an item into the BeadedBag if it doesn't already contain it.
void BeadedBag::insert(Item to_insert) {
    // Check if the item is not already in the BeadedBag
    if (!contains(to_insert)) {
        // Add the item to the BeadedBag
        items.push_back(to_insert);
    }
}

// Checks if the BeadedBag contains a specific item.
bool BeadedBag::contains(Item maybe_contained_item) {
    // Iterate through each item in the BeadedBag
    for (auto& item : items) {
        // Check if the current item is equal to the specified item
        if (item.isEqual(maybe_contained_item)) {
            // Item found in the BeadedBag
            return true;
        }
    }
    // Item not found in the BeadedBag
    return false;
}

// Returns the number of items in the BeadedBag.
int BeadedBag::size() {
    // Return the size of the items vector
    return items.size();
}
