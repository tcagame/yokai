#pragma once
#include "Enemy.h"

class EnemyPurpleYokai : public Enemy {
public:
	EnemyPurpleYokai( EnemyStockPtr enemy_stock, int x, int y, bool right = false );
	virtual ~EnemyPurpleYokai( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int _move_speed;
};

