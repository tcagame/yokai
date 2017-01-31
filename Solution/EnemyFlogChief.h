#pragma once

#include "Enemy.h"

PTR( EnemyStock );

class EnemyFlogChief : public Enemy {
public:
	EnemyFlogChief( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyFlogChief( );
private:
	void act( );
private:
	int _anime_count;
	EnemyStockPtr _stock;
};

