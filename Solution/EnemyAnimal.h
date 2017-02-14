#pragma once

#include "Enemy.h"

class EnemyAnimal : public Enemy {
public:
	EnemyAnimal( int x, int y, bool right = true );
	virtual ~EnemyAnimal( );
	virtual void damage( int pow );
	virtual Vector getOverlappedPos( ) const;
private:
	void act( );
private:
	int _act_count;
};

