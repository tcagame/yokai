#pragma once
#include "Enemy.h"

class EnemyDeceasedFourth : public Enemy {
public:
	EnemyDeceasedFourth( int x, int y );
	virtual ~EnemyDeceasedFourth( );
private:
	void act( );
private:
	int _count;
};

