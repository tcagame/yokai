#pragma once
#include "Enemy.h"

class EnemyMiasmaWhite : public Enemy {
public:
	EnemyMiasmaWhite( int x, int y );
	virtual ~EnemyMiasmaWhite( );
private:
	void act( );
};

