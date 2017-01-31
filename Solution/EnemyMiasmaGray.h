#pragma once

#include "Enemy.h"

class EnemyMiasmaGray : public Enemy {
public:
	EnemyMiasmaGray( int x, int y );
	virtual ~EnemyMiasmaGray( );
private:
	void act( );
private:
	int _anime_count;
	int _count;
	int _speed;
	int _vy;
	int _dir;
};

