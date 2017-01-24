#pragma once

#include "Boss.h"

class BossRedDemon : public Boss {
public:
	BossRedDemon( EnemyStockPtr enemy_stock );
	virtual ~BossRedDemon( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
};

