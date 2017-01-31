#pragma once
#include "Enemy.h"

class EnemyHandMonsterAttack : public Enemy {
public:
	EnemyHandMonsterAttack( int x, int y );
	virtual ~EnemyHandMonsterAttack( );
private:
	void act( );
	int _speed_y;
};

