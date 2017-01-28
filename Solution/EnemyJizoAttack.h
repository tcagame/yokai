#pragma once
#include "Enemy.h"

class EnemyJizoAttack : public Enemy {
public:
	EnemyJizoAttack( int x, int y );
	virtual ~EnemyJizoAttack( );
private:
	void act( );
};

