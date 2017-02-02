#pragma once
#include "Enemy.h"

class EnemyStoneRote : public Enemy {
public:
	EnemyStoneRote( int x, int y, bool right );
	virtual ~EnemyStoneRote( );
public:
	void act( );
private:
	int _act_count;
	int _before_x;
	int _move_speed;
};