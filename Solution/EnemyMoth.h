#pragma once
#include "Enemy.h"

class EnemyMoth : public Enemy {
public:
	EnemyMoth( int x, int y );
	virtual ~EnemyMoth( );
private:
	void act( );
private:
	int _anime_count;
};

