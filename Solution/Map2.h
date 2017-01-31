#pragma once

#include "Map.h"

class Map2  :public Map {
public:
	Map2( );
	virtual ~Map2( );
private:
	EnemyPtr generateEnemy( char ch, int x, int y ) const;
	BossPtr generateBoss( EnemyStockPtr stock ) const;
};

