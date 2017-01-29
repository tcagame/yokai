#pragma once

#include "Boss.h"
 
PTR( EnemyStock );

class BossBuddha : public Boss {
public:
	BossBuddha( EnemyStockPtr stock, int x );
	virtual ~BossBuddha( );
private:
	void act( );
	void attack( );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
	int _count;
};

