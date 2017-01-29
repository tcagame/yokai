#pragma once
#include "Enemy.h"

class EnemyHugDemon : public Enemy {
public:
	EnemyHugDemon( int x, int y );
	virtual ~EnemyHugDemon( );
private:
	void act( );
	void actMove( );
	void updateChip( );
};

