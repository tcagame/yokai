#pragma once
#include "Enemy.h"

class EnemyPurpleYokai : public Enemy {
public:
	EnemyPurpleYokai( int x, int y );
	virtual ~EnemyPurpleYokai( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
};

