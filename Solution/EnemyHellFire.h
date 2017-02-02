#pragma once
#include "Enemy.h"

class EnemyHellFire : public Enemy {
public:
	EnemyHellFire( int x, int y );
	virtual ~EnemyHellFire( );
private:
	void act( );
private:
	int _count;
};