#pragma once

#include "Enemy.h"

class EnemyTree : public Enemy {
public:
	EnemyTree( int x, int y );
	virtual ~EnemyTree( );
private:
	void act( );
	double getOverlappedRadius( ) const;
	Vector getOverlappedPos( ) const;
};
