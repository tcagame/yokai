#pragma once
#include "Enemy.h"

class EnemyRedFlogSmall : public Enemy {
public:
	EnemyRedFlogSmall( int x, int y );
	virtual ~EnemyRedFlogSmall( );
private:
	void act( );
};

