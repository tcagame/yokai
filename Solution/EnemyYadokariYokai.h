#pragma once
#include "Enemy.h"

class EnemyYadokariYokai : public Enemy {
public:
	EnemyYadokariYokai( int x, int y );
	virtual ~EnemyYadokariYokai( );
private:
	void act( );
};

