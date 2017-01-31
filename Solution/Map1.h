#pragma once

#include "Map.h"

class Map1  :public Map {
public:
	Map1( );
	virtual ~Map1( );
private:
	EnemyPtr generateEnemy( char ch, int x, int y ) const;
	BossPtr generateBoss( EnemyStockPtr stock ) const;
};

