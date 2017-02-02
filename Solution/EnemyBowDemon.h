#pragma once
#include "Enemy.h"

class EnemyBowDemon : public Enemy {
public:
	EnemyBowDemon( EnemyStockPtr enemy_stock, int x, int y, bool dir_right = false );
	virtual ~EnemyBowDemon( );
private:
	void act( );
private:
	EnemyStockPtr _stock;
	int _act_count;
	int _move_speed;
	int _before_x;	
};

