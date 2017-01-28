#pragma once
#include "Enemy.h"

class EnemyFlog : public Enemy {
public:
	EnemyFlog( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyFlog( );
public:
	void act( );
private:
	void updateChip( );
	void actAttack( );
private:
	int _act_count;
	EnemyStockPtr _stock;
};

