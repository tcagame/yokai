#pragma once
#include "Enemy.h"

class EnemyBat : public Enemy {
public:
	EnemyBat( int x, int y );
	virtual ~EnemyBat( );
private:
	void act( );
private:
	int _vy;
	int _dir;
};

