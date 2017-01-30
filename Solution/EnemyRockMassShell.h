#pragma once
#include "Enemy.h"

class EnemyRockMassShell : public Enemy {
public:
	EnemyRockMassShell( int x, int y );
	virtual ~EnemyRockMassShell( );
private:
	void act( );
private:
	int _act_count;
};

