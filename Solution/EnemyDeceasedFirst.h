#pragma once

#include "Enemy.h"

class EnemyDeceasedFirst : public Enemy {
public:
	EnemyDeceasedFirst( int x, int y );
	virtual ~EnemyDeceasedFirst( );
	virtual void damage( int pow );
private:
	void act( );
private:
	int _count;
	bool _talked;
};