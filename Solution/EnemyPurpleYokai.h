#pragma once

#include "Enemy.h"

class EnemyPurpleYokai : public Enemy {
public:
	EnemyPurpleYokai( int x, int y, bool right = false );
	virtual ~EnemyPurpleYokai( );
private:
	void act( );
private:
	int _move_speed;
};

