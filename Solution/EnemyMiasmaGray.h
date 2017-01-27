#pragma once
#include "Enemy.h"

PTR( EnemyStock );

class EnemyMiasmaGray : public Enemy {
public:
	EnemyMiasmaGray(  EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyMiasmaGray( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _anime_count;
};

