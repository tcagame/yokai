#pragma once

#include "Enemy.h"
#include "smart_ptr.h"

PTR( EnemyStock );

class Boss : public Enemy {
public:
	Boss( EnemyStockPtr enemy_stock, int x, int y, int hp, int pow );
	virtual ~Boss();
private:
	virtual bool isOutSideScreen( CameraConstPtr camera ) const;
};

