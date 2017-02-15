#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyCrow : public Enemy {
public:
	EnemyCrow( int x, int y, int patternt );
	virtual ~EnemyCrow( );
private:
	enum ACTION {
		ACTION_APPEAR,
		ACTION_WAIT,
		ACTION_MOVE,
	};
private:
	void act( );
	void actOnAppearing( );
	void actOnWaiting( );
	void actOnMoving( );
private:
	int _pattern;
	int _count;
	Vector _pos;
	Vector _vec;
	ACTION _action;
};

