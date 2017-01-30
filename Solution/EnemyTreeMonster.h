#pragma once

#include "Enemy.h"

class EnemyTreeMonster : public Enemy {
public:
	EnemyTreeMonster( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyTreeMonster ( );
private:
	void act( );
	double getOverlappedRadius( ) const;
	int _count;
private:
	int x;
	int y;
	EnemyStockPtr _stock;
	Vector getOverlappedPos( ) const;
};
