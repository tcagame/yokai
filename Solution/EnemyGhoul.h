#pragma once
#include "Enemy.h"

class EnemyGhoul : public Enemy {
public:
	EnemyGhoul( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyGhoul( );
private:
	void act( );
	void actMove( );
	void updateChip( );
private:
	int _count;
};
