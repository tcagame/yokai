#pragma once
#include "Enemy.h"

class EnemyBowDemon : public Enemy {
public:
	EnemyBowDemon( int x, int y );
	virtual ~EnemyBowDemon( );
public:
	void act( );;
};

