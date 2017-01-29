#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyCrow : public Enemy {
public:
	EnemyCrow( int x, int y, const Vector& target );
	virtual ~EnemyCrow( );
private:
	void act( );
private:
	int _count;
	Vector _pos;
	Vector _vec;
	Vector _target;
};

