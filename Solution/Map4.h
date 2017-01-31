#pragma once

#include "Map.h"

class Map4  :public Map {
public:
	Map4( );
	virtual ~Map4( );
private:
	EnemyPtr generateEnemy( char ch, int x, int y ) const;
	BossPtr  generateBoss( EnemyStockPtr stock ) const;
};

