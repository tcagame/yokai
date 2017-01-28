#pragma once
#include "Enemy.h"

class EnemyGhoul : public Enemy {
public:
	EnemyGhoul( int x, int y );
	virtual ~EnemyGhoul( );
private:
	void act( );
private:
	int _count;
};
