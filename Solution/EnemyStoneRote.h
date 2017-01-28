#pragma once
#include "Enemy.h"

class EnemyStoneRote : public Enemy {
public:
	EnemyStoneRote( int x, int y );
	virtual ~EnemyStoneRote( );
public:
	void act( );
private:
	int _act_count;
};