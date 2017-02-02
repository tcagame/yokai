#pragma once
#include "Enemy.h"

class EnemyJizo : public Enemy {
public:
	EnemyJizo( EnemyStockPtr enemy_stock, int x, int y, bool dir_right = false );
	virtual ~EnemyJizo( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_APPEAR,
		ACTION_NOMAL,
		MAX_ACTION
	};
private:
	void act( );
	void actNomal( );
	void actWait( );
	void updateChip( );
private:
	int _move_speed;
	int _before_x;
	ACTION _action;
	int _act_count;
	EnemyStockPtr _stock;
};