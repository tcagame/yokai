#pragma once
#include "Enemy.h"

class EnemyRedbirdAttack : public Enemy {
public:
	EnemyRedbirdAttack( int x, int y );
	virtual ~EnemyRedbirdAttack( );
public:
	void act( );
	void actMove( );
	void updateChip( );
};

