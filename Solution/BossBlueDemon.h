#pragma once

#include "Boss.h"

class BossBlueDemon : public Boss {
public:
	BossBlueDemon( EnemyStockPtr enemy_stock, int x );
	virtual ~BossBlueDemon( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
	void attack( );
	double getOverlappedRadius( ) const;
private:
	int _count;
};

