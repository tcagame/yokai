#pragma once
#include "Enemy.h"

class EnemyRedbird : public Enemy {
public:
	EnemyRedbird( int x, int y );
	virtual ~EnemyRedbird( );
public:
	void act( );
private:
	void actMove( );
	void actAttack( );
	void updateChip( );
private:
	int _attack_count;
	int _accel;
};

