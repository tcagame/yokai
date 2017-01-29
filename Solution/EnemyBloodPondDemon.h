#pragma once
#include "Enemy.h"

class EnemyBloodPondDemon : public Enemy {
public:
	EnemyBloodPondDemon( int x, int y );
	virtual ~EnemyBloodPondDemon( );
private:
	enum ACTION {
		ACTION_WAIT,
		ACTION_ATTACK,
		MAX_ACTION
	};
private:
	void act( );
	void updateChip( );
	void updateChipAttack( );
private:
	ACTION _action;
	int _act_count;
};

