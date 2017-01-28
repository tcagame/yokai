#pragma once
#include "Enemy.h"

class EnemyWaterGhost : public Enemy {
public:
	EnemyWaterGhost( int x, int y );
	virtual ~EnemyWaterGhost( );
public:
	void act( );
private:
	int _act_count;
};