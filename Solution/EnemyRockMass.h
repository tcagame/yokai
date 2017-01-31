#pragma once

#include "Enemy.h"

class EnemyRockMass : public Enemy {
public:
	EnemyRockMass( int x, int y );
	virtual ~EnemyRockMass( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
private:
	int _count;
};

