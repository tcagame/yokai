#pragma once
#include "Enemy.h"

class EnemyDeceasedThird : public Enemy {
public:
	EnemyDeceasedThird( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyDeceasedThird( );
private:
	void act( );
private:
	int _count;
};

