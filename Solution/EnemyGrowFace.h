#pragma once
#include "Enemy.h"

PTR( EnemyStock );

class EnemyGrowFace : public Enemy{
public:
	EnemyGrowFace( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyGrowFace( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _anime_count;
	int _y;
};

