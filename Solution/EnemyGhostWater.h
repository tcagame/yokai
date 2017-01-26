#pragma once
#include "Enemy.h"

class EnemyGhostWater : public Enemy {
public:
	EnemyGhostWater( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyGhostWater( );
public:
	void act( );
private:
	void updateChip( );
private:
	int _act_count;
};