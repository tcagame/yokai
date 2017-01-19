#pragma once
#include "Enemy.h"

class EnemyRedbird : public Enemy {
public:
	EnemyRedbird( int x, int y );
	virtual ~EnemyRedbird( );
public:
	void act( );
	void actMove( );
	void updateChip( );
};

