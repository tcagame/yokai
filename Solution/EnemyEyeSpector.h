#pragma once
#include "Enemy.h"

class EnemyEyeSpector : public Enemy {
public:
	EnemyEyeSpector( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyEyeSpector( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _act_count;
};

