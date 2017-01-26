#pragma once
#include "Enemy.h"

class EnemyOnyudo : public Enemy {
public:
	EnemyOnyudo( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyOnyudo( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
};

