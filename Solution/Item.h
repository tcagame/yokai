#pragma once
#include "Character.h"

class Item : public Character {
public:
	Item( int x, int y );
	virtual ~Item();
};

