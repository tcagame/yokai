#pragma once

#include "Map.h"

class Map3  :public Map {
public:
	Map3( );
	virtual ~Map3( );
private:
	EnemyPtr generateEnemy( char ch, int x, int y ) const;
	BossPtr generateBoss( EnemyStockPtr stock ) const;
};