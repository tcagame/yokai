#pragma once
#include "Enemy.h"

class EnemyDeceasedSecond : public Enemy {
public:
	EnemyDeceasedSecond( int x, int y );
	virtual ~EnemyDeceasedSecond( );
private:
	void act( );
private:
	int _count;
};

