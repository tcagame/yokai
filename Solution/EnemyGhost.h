#pragma once

#include "smart_ptr.h"
#include "Enemy.h"
#include "mathmatics.h"

PTR( EnemyStock );

class EnemyGhost : public Enemy {
public:
	EnemyGhost( EnemyStockPtr stock, int x, int y, const Vector& target );
	virtual ~EnemyGhost( );
private:
	void act( );
private:
	int _count;
	Vector _pos;
	Vector _vec;
	Vector _target;
};

