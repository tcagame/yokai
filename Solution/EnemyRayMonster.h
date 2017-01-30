#pragma once
#include "Enemy.h"

class EnemyRayMonster : public Enemy {
public:
	EnemyRayMonster( int x, int y );
	virtual ~EnemyRayMonster( );
private:
	void act( );
};

