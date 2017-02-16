#pragma once
#include "Enemy.h"

class EnemyBranchMonsterAttack : public Enemy {
public:
	EnemyBranchMonsterAttack( int x, int y );
	virtual ~EnemyBranchMonsterAttack( );
private:
	void act( );
	void damage( int pow );
private:
	int _anime_count;
	int _jump_power;
};
