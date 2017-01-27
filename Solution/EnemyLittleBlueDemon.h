#pragma once

#include "smart_ptr.h"
#include "mathmatics.h"
#include "Enemy.h"

PTR( EnemyStock );

class EnemyLittleBlueDemon : public Enemy {
public:
	EnemyLittleBlueDemon( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyLittleBlueDemon( );
private:
	void act( );
private:
	int _count;
};
