#pragma once
#include "Enemy.h"

class EnemyDeceasedFourth : public Enemy {
public:
	EnemyDeceasedFourth( int x, int y );
	virtual ~EnemyDeceasedFourth( );
	virtual void damage( int pow );
private:
	void act( );
private:
	int _count;
};

