#ifndef __BEADEDBAG_BEADEDBAG_HPP
#define __BEADEDBAG_BEADEDBAG_HPP

#include "item.h"
#include <vector>

class BeadedBag {
public:
	void insert(Item to_insert);
	bool contains(Item maybe_contained_item);
	int size();

private:
	std::vector<Item> items;
	

};

#endif