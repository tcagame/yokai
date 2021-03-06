#pragma once

#include "Boss.h"

class BossHag : public Boss {
public:
	BossHag( EnemyStockPtr stock, int x );
	virtual ~BossHag( );
private:
	void act( );
	void attack( );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
	int _count;
};
