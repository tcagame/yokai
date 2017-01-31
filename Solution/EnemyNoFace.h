#pragma once

#include "Enemy.h"

class EnemyNoFace : public Enemy {
public:
	EnemyNoFace( int x, int y );
	virtual ~EnemyNoFace( );
private:
	void act( );
private:
	int _anime_count;
};
