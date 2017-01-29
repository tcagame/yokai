#pragma once

#include "Boss.h"
 
PTR( EnemyStock );

class BossBuddha : public Boss {
public:
	BossBuddha( EnemyStockPtr stock, int x );
	virtual ~BossBuddha();
private:
	void act( );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
};

