#pragma once

#include "Enemy.h"

class EnemyAnimal : public Enemy {
public:
	EnemyAnimal( int x, int y, bool right = false );
	virtual ~EnemyAnimal( );
	virtual void damage( int pow );
	virtual Vector getOverlappedPos( ) const;
private:
	void act( );
private:
	int _act_count;
	int _wait_count;
	int _move_speed;
};