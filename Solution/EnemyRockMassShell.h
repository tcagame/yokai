#pragma once
#include "Enemy.h"

PTR( EnemyStoneMortgage )

class EnemyRockMassShell : public Enemy {
public:
	EnemyRockMassShell( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyRockMassShell( );
	void damage( int pow );
private:
	void act( );
};

