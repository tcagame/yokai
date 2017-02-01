#pragma once
#include "Enemy.h"

class EnemyShishimaiDemon : public Enemy {
public:
	EnemyShishimaiDemon( int x, int y );
	virtual ~EnemyShishimaiDemon( );
private:
	void act( );
private:
	int _act_count;
	int _move_speed;
	int _before_x;
};

