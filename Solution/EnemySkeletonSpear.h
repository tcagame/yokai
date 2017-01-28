#pragma once

#include "Enemy.h"

class EnemySkeletonSpear : public Enemy {
public:
	EnemySkeletonSpear( int x, int y );
	virtual ~EnemySkeletonSpear( );
private:
	void act( );
};

