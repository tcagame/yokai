#pragma once
#include "Enemy.h"

class EnemyStoneFly : public Enemy {
public:
	EnemyStoneFly( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyStoneFly( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _act_count;
};

