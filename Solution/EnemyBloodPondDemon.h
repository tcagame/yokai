#pragma once
#include "Enemy.h"

class EnemyBloodPondDemon : public Enemy {
public:
	EnemyBloodPondDemon( int x, int y );
	virtual ~EnemyBloodPondDemon( );
private:
	void act( );
	void updateChip( );
};

