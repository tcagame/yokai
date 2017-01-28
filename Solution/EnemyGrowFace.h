#pragma once
#include "Enemy.h"

class EnemyGrowFace : public Enemy{
public:
	EnemyGrowFace( int x, int y );
	virtual ~EnemyGrowFace( );
private:
	void act( );
private:
	int _anime_count;
	int _y;
};

