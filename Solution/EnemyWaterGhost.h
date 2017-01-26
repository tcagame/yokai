#pragma once
#include "Enemy.h"

class EnemyWaterGhost : public Enemy {
public:
	EnemyWaterGhost( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyWaterGhost( );
public:
	void act( );
private:
	void updateChip( );
private:
	int _act_count;
};