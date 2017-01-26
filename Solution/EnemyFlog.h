#pragma once
#include "Enemy.h"

class EnemyFlog : public Enemy {
public:
	EnemyFlog( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyFlog( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
	void steppedOn( );
private:
	int _act_count;
	int _smashed_count;
};