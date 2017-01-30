#pragma once

#include "Boss.h"

class BossEnma : public Boss {
public:
	BossEnma( EnemyStockPtr stock, int x );
	virtual ~BossEnma( );
private:
	void act( );
	void attack( );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
	int _count;
};
