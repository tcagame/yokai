#pragma once
#include "Enemy.h"

class EnemyRollOverNeckWoman : public Enemy {
public:
	EnemyRollOverNeckWoman( int x, int y );
	virtual ~EnemyRollOverNeckWoman( );
private:
	void act( );
};