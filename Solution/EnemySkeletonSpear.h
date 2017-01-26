#pragma once
#include "Enemy.h"

class EnemySkeletonSpear : public Enemy {
public:
	EnemySkeletonSpear( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemySkeletonSpear( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
};

