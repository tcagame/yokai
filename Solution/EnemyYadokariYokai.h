#pragma once
#include "Enemy.h"

class EnemyYadokariYokai : public Enemy {
public:
	EnemyYadokariYokai( int x, int y );
	virtual ~EnemyYadokariYokai( );
public:
	enum ACTION {
		ACTION_APPEAR,
		ACTION_NOMAL,
		ACTION_MAX
	};
private:
	void act( );
	void updateChip( );
private:
	ACTION _action;
	int _act_count;
};