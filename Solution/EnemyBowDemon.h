#pragma once
#include "Enemy.h"

class EnemyBowDemon : public Enemy {
public:
	EnemyBowDemon( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyBowDemon( );
private:
	void act( );
private:
	EnemyStockPtr _enemy_stock;
	int _act_count;
};

