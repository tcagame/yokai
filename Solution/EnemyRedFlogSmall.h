#pragma once
#include "Enemy.h"

class EnemyRedFlogSmall : public Enemy {
public:
	EnemyRedFlogSmall( int x, int y );
	virtual ~EnemyRedFlogSmall( );
private:
	void act( );
	void steppedOn( );
private:
	int _act_count;
	int _smashed_count;
	int _time;
};

