#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyFire : public Enemy{
public:
	EnemyFire( const Vector& pos, const Vector& vec );
	virtual~EnemyFire( );
private:
	void act( );
private:
	Vector _pos;
	Vector _vec;
};
