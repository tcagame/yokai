#pragma once
#include "Enemy.h"

class EnemyMiasmaWhite : public Enemy {
public:
	EnemyMiasmaWhite( int x, int y, bool dir_right = false );
	virtual ~EnemyMiasmaWhite( );
private:
	void act( );
private:
	int _move_speed;
	int _vy;
	int _dir;
};

