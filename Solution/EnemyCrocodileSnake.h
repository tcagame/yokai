#pragma once
#include "smart_ptr.h"
#include "Enemy.h"

PTR( EnemyStock )

class EnemyCrocodileSnake : public Enemy {
public:
	EnemyCrocodileSnake( EnemyStockPtr stock, int x, int y, bool dir_right = false );
	virtual ~EnemyCrocodileSnake( );
private:
	void act( );
	void actMove( );
	void updateChip( );
	void attack( );
private:
	int _move_speed;
	int _before_x;
	EnemyStockPtr _stock;
};