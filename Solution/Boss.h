#pragma once

#include "Enemy.h"
#include "smart_ptr.h"

PTR( EnemyStock );

class Boss :	public Enemy {
public:
	Boss( EnemyStockPtr enemy_stock );
	virtual ~Boss();
};

