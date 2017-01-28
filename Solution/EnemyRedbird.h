#pragma once
#include "Enemy.h"

class EnemyRedbird : public Enemy {
public:
	EnemyRedbird( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyRedbird( );
private:
	void act( );
private:
	EnemyStockPtr _stock;
	int _accel;
	int _count;
};

