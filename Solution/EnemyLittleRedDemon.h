#pragma once

#include "smart_ptr.h"
#include "Enemy.h"
#include "mathmatics.h"

PTR( EnemyStock );

class EnemyLittleRedDemon : public Enemy {
public:
	EnemyLittleRedDemon( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyLittleRedDemon( );
private:
	void act( );
private:
	int _count;
};

