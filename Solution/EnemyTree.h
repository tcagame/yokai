#pragma once

#include "Enemy.h"

class EnemyTree : public Enemy {
public:
	EnemyTree( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyTree( );
private:
	void act( );
	double getOverlappedRadius( ) const;
	int _count;
private:
	EnemyStockPtr _stock;
	Vector getOverlappedPos( ) const;
};
