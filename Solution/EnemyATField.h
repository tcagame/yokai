#pragma once

#include "Enemy.h"

class EnemyATField : public Enemy {
public:
	EnemyATField( int x, int y );
	~EnemyATField( );
	void damage( int pow );

private:
	void act( );
};
