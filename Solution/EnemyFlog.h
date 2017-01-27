#pragma once
#include "Enemy.h"

class EnemyFlog : public Enemy {
public:
	EnemyFlog( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyFlog( );
public:
	void act( );
private:
	void updateChip( );
};

