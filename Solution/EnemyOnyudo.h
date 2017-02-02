#pragma once
#include "Enemy.h"

class EnemyOnyudo : public Enemy {
public:
	EnemyOnyudo( int x, int y, bool dir_right = false );
	virtual ~EnemyOnyudo( );
private:
	void act( );
	int _move_speed;
	int _before_x;
};

