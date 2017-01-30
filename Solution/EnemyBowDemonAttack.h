#pragma once
#include "Enemy.h"

class EnemyBowDemonAttack : public Enemy {
public:
	EnemyBowDemonAttack( int x, int y );
	virtual ~EnemyBowDemonAttack( );
private:
	void act( );
};

