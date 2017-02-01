#pragma once
#include "Enemy.h"

class EnemyWaterGhost : public Enemy {
public:
	EnemyWaterGhost( int x, int y );
	virtual ~EnemyWaterGhost( );
public:
	void act( );
	Vector getOverlappedPos( ) const;
private:
	int _act_count;
	bool _in_water;
};