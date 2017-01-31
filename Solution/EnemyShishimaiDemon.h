#pragma once
#include "Enemy.h"

class EnemyShishimaiDemon : public Enemy {
public:
	EnemyShishimaiDemon( int x, int y );
	virtual ~EnemyShishimaiDemon( );
private:
	void act( );
};

