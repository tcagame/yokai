#pragma once

#include "Enemy.h"

class EnemyDeceased : public Enemy {
public:
	EnemyDeceased( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyDeceased( );

private:
	void act( );
private:
	int _count;
};