#pragma once
#include "Enemy.h"

class EnemyEyeSpector : public Enemy {
public:
	EnemyEyeSpector( int x, int y );
	virtual ~EnemyEyeSpector( );
private:
	void act( );
	void actMove( );
	void updateChip( );
private:
	int _act_count;
};

