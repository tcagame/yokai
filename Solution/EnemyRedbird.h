#pragma once
#include "Enemy.h"

class EnemyRedbird : public Enemy {
public:
	EnemyRedbird( EnemyStockPtr stock, int x, int y, bool dir_right = true );
	virtual ~EnemyRedbird( );
private:
	void act( );
private:
	EnemyStockPtr _stock;
	int _move_speed;
	int _accel;
	int _count;
};

