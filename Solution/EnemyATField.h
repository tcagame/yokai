#pragma once

#include "Enemy.h"

class EnemyATField : public Enemy {
public:
	EnemyATField( int x, int y );
	~EnemyATField( );
private:
	void act( );
	void damage( int pow );
};
