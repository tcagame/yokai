#pragma once
#include "Enemy.h"

class EnemyOnyudo : public Enemy {
public:
	EnemyOnyudo( int x, int y );
	virtual ~EnemyOnyudo( );
private:
	void act( );
};

