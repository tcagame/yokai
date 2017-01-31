#pragma once

#include "Map.h"

class Map0  :public Map {
public:
	Map0( );
	virtual ~Map0( );
private:
	EnemyPtr generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const;
	BossPtr generateBoss( EnemyStockPtr stock ) const;
};

