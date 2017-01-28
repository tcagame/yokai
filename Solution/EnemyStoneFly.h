#pragma once

#include "Enemy.h"

class EnemyStoneFly : public Enemy {
public:
	EnemyStoneFly( int x, int y );
	virtual ~EnemyStoneFly( );
private:
	void act( );
private:
	int _act_count;
};

