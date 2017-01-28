#pragma once
#include "Enemy.h"

class EnemyWaterMonk : public Enemy {
public:
	EnemyWaterMonk( int x, int y );
	virtual ~EnemyWaterMonk( );
public:
	void act( );
private:
	int _act_count;
};