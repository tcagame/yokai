#pragma once

#include "Enemy.h"

class EnemyFlogChief : public Enemy {
public:
	EnemyFlogChief( int x, int y );
	virtual ~EnemyFlogChief( );
private:
	void act( );
private:
	int _anime_count;
};

