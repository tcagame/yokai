#pragma once
#include "Enemy.h"

class EnemyNoNeckGhost : public Enemy {
public:
	EnemyNoNeckGhost( int x, int y );
	virtual~EnemyNoNeckGhost( );
private:
	void act( );
private:
	int _count;
	int _speed;
	int _vy;
	int _dir;
};


