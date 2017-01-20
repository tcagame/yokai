#pragma once
#include "Enemy.h"

PTR( EnemyStock );

class EnemyMoth : public Enemy {
public:
	EnemyMoth( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyMoth( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _anime_count;
};

