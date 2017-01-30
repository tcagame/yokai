#pragma once

#include "Enemy.h"

class EnemyBranchMonster: public Enemy {
public:
	EnemyBranchMonster( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyBranchMonster( );
private:
	void act( );
	void actGrow( );
	void actAttack( );
private:
	enum ACTION {
		ACTION_GROW,
		ACTION_ATTACK,
		MAX_ACTION
	};
private:
	int _anime_count;
	int _y;
	int _action;
	int _count;
	EnemyStockPtr _stock;
};


