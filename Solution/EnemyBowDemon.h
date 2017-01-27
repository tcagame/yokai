#pragma once
#include "Enemy.h"

class EnemyBowDemon : public Enemy {
public:
	EnemyBowDemon( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyBowDemon( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
};

