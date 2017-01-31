#pragma once

#include "Map.h"

class MapTest  :public Map {
public:
	MapTest( );
	virtual ~MapTest( );
private:
	EnemyPtr generateEnemy( char ch, EnemyStockPtr stock, int x, int y ) const;
	BossPtr  generateBoss( EnemyStockPtr stock ) const;	
};

