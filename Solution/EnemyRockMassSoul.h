#pragma once

#include "Enemy.h"

class EnemyRockMassSoul:
	public Enemy {
public:
	EnemyRockMassSoul( int x, int y );
	virtual ~EnemyRockMassSoul( );
private:
	void act( );
	void updateChip( );
private:
	int _count;
};

