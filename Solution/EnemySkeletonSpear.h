#pragma once

#include "Enemy.h"

class EnemySkeletonSpear : public Enemy {
public:
	EnemySkeletonSpear( int x, int y );
	virtual ~EnemySkeletonSpear( );
private:
	void act( );
private:
	int _move_speed;
	int _before_x;
};

