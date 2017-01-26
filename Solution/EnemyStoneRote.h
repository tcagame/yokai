#pragma once
#include "Enemy.h"

class EnemyStoneRote : public Enemy {
public:
	EnemyStoneRote( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyStoneRote( );
public:
	void act( );
private:
	void updateChip( );
	void actMove( );
private:
	int _act_count;
};