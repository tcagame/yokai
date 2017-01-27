#pragma once
#include "Enemy.h"

class EnemyFlogSmall : public Enemy {
public:
	EnemyFlogSmall( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyFlogSmall( );
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