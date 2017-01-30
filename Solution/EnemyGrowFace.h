#pragma once
#include "Enemy.h"

class EnemyGrowFace : public Enemy{
public:
	EnemyGrowFace( int x, int y );
	virtual ~EnemyGrowFace( );
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
};

