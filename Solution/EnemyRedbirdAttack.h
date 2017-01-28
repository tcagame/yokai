#pragma once
#include "Enemy.h"

class EnemyRedbirdAttack : public Enemy {
public:
	EnemyRedbirdAttack( int x, int y );
	virtual ~EnemyRedbirdAttack( );
private:
	void act( );
private:
	int _act_count;
};

