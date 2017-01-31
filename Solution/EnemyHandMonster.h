#pragma once
#include "Enemy.h"

class EnemyHandMonster : public Enemy {
public:
	EnemyHandMonster( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyHandMonster( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_THROW,
		MAX_ACTION,
	};
private:
	void act( );
	void actWait( );
	void actThrow( );
private:
	int _act_count;
	ACTION _action;
	EnemyStockPtr _stock;
};