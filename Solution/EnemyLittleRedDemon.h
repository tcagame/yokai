#pragma once

#include "smart_ptr.h"
#include "Enemy.h"

class EnemyLittleRedDemon : public Enemy {
public:
	EnemyLittleRedDemon( int x, int y );
	virtual ~EnemyLittleRedDemon( );
private:
	void act( );
private:
	int _count;
};

