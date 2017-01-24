#pragma once
#include "Enemy.h"

class EnemyDeceasedFourth : public Enemy {
public:
	EnemyDeceasedFourth( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyDeceasedFourth( );
private:
	void act( );
private:
	int _count;
};

