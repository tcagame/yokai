#pragma once
#include "Enemy.h"

class EnemyRayMonster : public Enemy {
public:
	EnemyRayMonster( int x, int y );
	virtual ~EnemyRayMonster( );
private:
	void act( );
	Vector getOverlappedPos( ) const;
	double getOverlappedRadius( ) const;
private:
	int _count;
	int _speed;
	bool _revers;
};

