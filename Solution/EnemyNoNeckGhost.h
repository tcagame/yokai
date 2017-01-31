#pragma once
#include "Enemy.h"

class EnemyNoNeckGhost : public Enemy {
public:
	EnemyNoNeckGhost( int x, int y );
	virtual~EnemyNoNeckGhost( );
private:
	void act( );
private:
	int _accel;
	int _count;
};


