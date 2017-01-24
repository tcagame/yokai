#pragma once

#include "Enemy.h"

class EnemyDeceasedFirst : public Enemy {
public:
	EnemyDeceasedFirst( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyDeceasedFirst( );

private:
	void act( );
private:
	int _count;
};