#pragma once

#include "Enemy.h"

class EnemyBranchMonster: public Enemy {
public:
	EnemyBranchMonster( int x, int y );
	virtual ~EnemyBranchMonster( );
private:
	void actGrow( );
	void act( );

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
};


