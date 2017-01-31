#pragma once
#include "Enemy.h"

class EnemyWindMonsterAttack : public Enemy {
public:
	EnemyWindMonsterAttack( int x, int y );
	virtual ~EnemyWindMonsterAttack( );
private:
	void act( );
private:
	int _act_count;
};

