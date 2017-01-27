#pragma once
#include "Enemy.h"

class BowDemon : public Enemy {
public:
	BowDemon( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~BowDemon( );
};

