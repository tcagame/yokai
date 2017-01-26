#pragma once
#include "Enemy.h"

class EnemyWaterMonk : public Enemy {
public:
	EnemyWaterMonk( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyWaterMonk( );
public:
	void act( );
private:
	void updateChip( );
private:
	int _act_count;
};