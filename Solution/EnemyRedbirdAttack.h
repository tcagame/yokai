#pragma once
#include "Enemy.h"

class EnemyRedbirdAttack : public Enemy {
public:
	EnemyRedbirdAttack( EnemyStockPtr enemy_stock, int x, int y );
	virtual ~EnemyRedbirdAttack( );
public:
	void act( );
private:
	void actMove( );
	void updateChip( );
private:
	int anime_count;
};

