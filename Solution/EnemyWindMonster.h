#pragma once
#include "Enemy.h"

class EnemyWindMonster : public Enemy {
public:
	EnemyWindMonster( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyWindMonster( );
private:
	void act( );
private:
	int _act_count;
	EnemyStockPtr _stock;
};

