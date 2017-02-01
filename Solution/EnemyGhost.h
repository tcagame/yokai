#pragma once

#include "smart_ptr.h"
#include "Enemy.h"
#include "mathmatics.h"

PTR( EnemyStock );

class EnemyGhost : public Enemy {
public:
	EnemyGhost( int x, int y );
	virtual ~EnemyGhost( );
private:
	void act( );
private:
	int _count;
	Vector _pos;
	Vector _vec;
};

