#pragma once
#include "Enemy.h"

class EnemyBowDemonAttack : public Enemy {
public:
	EnemyBowDemonAttack( int x, int y, bool dir_right = false );
	virtual ~EnemyBowDemonAttack( );
private:
	void act( );
private:
	int _move_speed;
};

