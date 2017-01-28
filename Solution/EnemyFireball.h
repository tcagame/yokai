#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyFireball : public Enemy {
public:
	EnemyFireball( const Vector& pos, const Vector& vec );
	virtual ~EnemyFireball( );
private:
	void act( );
private:
	Vector _pos;
	Vector _vec;
};

