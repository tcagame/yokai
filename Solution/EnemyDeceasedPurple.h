#pragma once

#include "Enemy.h"

class EnemyDeceasedPurple : public Enemy {
public:
	EnemyDeceasedPurple( int x, int y, bool right = false );
	virtual ~EnemyDeceasedPurple( );
private:
	void act( );
private:
	int _move_speed;
	int _before_x;
};

