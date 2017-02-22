#pragma once
#include "Enemy.h"

class EnemyHellFire : public Enemy {
public:
	EnemyHellFire( int x, int y, int hp );
	virtual ~EnemyHellFire( );
private:
	void act( );
private:
	int _act_count;
	Vector _pos;
	Vector _vec;
};