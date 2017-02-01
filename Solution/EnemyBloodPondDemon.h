#pragma once
#include "Enemy.h"

PTR( EnemyStock );


class EnemyBloodPondDemon : public Enemy {
public:
	EnemyBloodPondDemon( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyBloodPondDemon( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_ATTACK,
		MAX_ACTION
	};
private:
	void act( );
	void attack( );
	void updateChip( );
private:
	ACTION _action;
	int _count;
	EnemyStockPtr _stock;
};

