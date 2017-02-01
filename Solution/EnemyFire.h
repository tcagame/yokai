#pragma once

#include "Enemy.h"
#include "mathmatics.h"
#include <array>

PTR( Camera );

class EnemyFire : public Enemy {
public:
	EnemyFire( const Vector& pos, const Vector& vec, const Vector& target );
	virtual~EnemyFire( );
private:
	void act( );
	bool isOutSideScreen( CameraConstPtr camera ) const;
	virtual void draw( CameraConstPtr camera, bool bright = false ) const;
private:
	Vector _target;
	Vector _pos;
	Vector _vec;
	static const int TAIL_NUM = 30;
	static const int DIV_NUM = 5;
	std::array< Vector, TAIL_NUM > _tails;
};
