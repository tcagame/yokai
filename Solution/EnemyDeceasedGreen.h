#pragma once

#include "Enemy.h"

class EnemyDeceasedGreen : public Enemy {
public:
	EnemyDeceasedGreen( int x, int y, bool right = false );
	virtual ~EnemyDeceasedGreen( );
private:
	void act( );
private:
	int _move_speed;
};