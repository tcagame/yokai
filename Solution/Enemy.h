#pragma once
#include "Character.h"

class Enemy : public Character {
public:
	Enemy( int x, int y, int chip_graph, bool mass = true );
	virtual ~Enemy( );
};

