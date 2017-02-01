#pragma once

#include "Enemy.h"

class EnemyBlueMonk : public Enemy {
public:
	EnemyBlueMonk( int x, int y );
	virtual ~EnemyBlueMonk( );
private:
	void act( );
private:
	int _count;
	int _move_speed;
	int _before_x;
};
