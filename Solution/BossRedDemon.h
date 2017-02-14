#pragma once

#include "Boss.h"

class BossRedDemon : public Boss {
public:
	BossRedDemon( EnemyStockPtr stock, int x );
	virtual ~BossRedDemon( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
	void attack( );
	void damage( int pow );
	double getOverlappedRadius( ) const;
private:
	EnemyStockPtr _stock;
	int _count;
};

