#pragma once
#include "Enemy.h"

class EnemyWaterMonk : public Enemy {
public:
	EnemyWaterMonk( int x, int y );
	virtual ~EnemyWaterMonk( );
private:
	void act( );
	Vector getOverlappedPos( ) const;
private:
	int _act_count;
	bool _in_water;
};