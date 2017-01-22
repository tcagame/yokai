#pragma once
#include "Enemy.h"

PTR( EnemyStock );

class EnemyTree : public Enemy {
public:
	EnemyTree( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyTree( );
public:
	void act( );
	double getOverlappedRadius( ) const;
	Vector getOverlappedPos( ) const;
};
