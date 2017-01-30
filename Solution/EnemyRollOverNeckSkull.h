#pragma once
#include "Enemy.h"

class EnemyRollOverNeckSkull : public Enemy {
public:
	EnemyRollOverNeckSkull( int x, int y );
	virtual ~EnemyRollOverNeckSkull( );
private:
	void act( );
};