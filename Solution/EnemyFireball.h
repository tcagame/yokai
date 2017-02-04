#pragma once

#include "Enemy.h"
#include "mathmatics.h"

class EnemyFireball : public Enemy {
public:
	EnemyFireball( const Vector& pos, const Vector& vec, bool dir_right = false );
	virtual ~EnemyFireball( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
private:
	Vector _pos;
	Vector _vec;
	int _u;
	int _v;
	int _count;
};

