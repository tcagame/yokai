#pragma once
#include "Enemy.h"

class EnemyStone : public Enemy {
public:
	EnemyStone( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyStone( );
public:
	void act( );
private:
	void updateChip( );
	void actMove( );
private:
	int _act_count;
};