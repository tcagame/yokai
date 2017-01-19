#pragma once
#include "Character.h"

static const int ENEMY_SIZE = 204;
static const int ENEMY_FOOT = 0;

class Enemy : public Character {
public:
	Enemy( int x, int y, int chip_graph, int chip_size = ENEMY_SIZE, int enemy_foot = ENEMY_FOOT, bool mass = true );
	virtual ~Enemy( );
};

