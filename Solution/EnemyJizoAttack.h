#pragma once
#include "Enemy.h"

class EnemyJizoAttack : public Enemy {
public:
	EnemyJizoAttack( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyJizoAttack( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
};

