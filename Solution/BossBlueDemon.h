#pragma once

#include "Boss.h"

class BossBlueDemon : public Boss {
public:
	BossBlueDemon( EnemyStockPtr stock, int x );
	virtual ~BossBlueDemon( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
	void attack( );
	double getOverlappedRadius( ) const;
	void damage( int pow );
private:
	EnemyStockPtr _stock;
	int _count;
};

