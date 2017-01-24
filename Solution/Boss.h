#pragma once
#include "Enemy.h"
class Boss:
	public Enemy
{
public:
	Boss( EnemyStockPtr enemy_stock );
	virtual ~Boss();
};

