#pragma once

#include "Enemy.h"

class EnemyShishimai : public Enemy {
public:
	EnemyShishimai( int x, int y );
	virtual ~EnemyShishimai( );
private:
	void act( );
private:
	int _act_count;
	int _move_speed;
	int _old_x;
	int _old_y;
};
