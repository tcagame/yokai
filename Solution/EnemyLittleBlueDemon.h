#pragma once

#include "smart_ptr.h"
#include "Enemy.h"

class EnemyLittleBlueDemon : public Enemy {
public:
	EnemyLittleBlueDemon( int x, int y );
	virtual ~EnemyLittleBlueDemon( );
private:
	void act( );
private:
	int _count;
};
