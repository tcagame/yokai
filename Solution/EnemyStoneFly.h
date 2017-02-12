#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyStoneFly : public Enemy {
public:
	EnemyStoneFly( int x, int y );
	virtual ~EnemyStoneFly( );
private:
	void act( );
private:
	int _act_count;
	Vector _pos;
	Vector _vec;
};

