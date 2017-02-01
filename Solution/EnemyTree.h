#pragma once

#include "Enemy.h"

class EnemyTree : public Enemy, public std::enable_shared_from_this< EnemyTree > {
public:
	EnemyTree( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyTree( );
private:
	void act( );
	double getOverlappedRadius( ) const;
	int _count;
private:
	int _create_idx;
	EnemyStockPtr _stock;
	Vector getOverlappedPos( ) const;
};
