#pragma once

#include "Enemy.h"

class EnemyShishimai : public Enemy {
public:
	EnemyShishimai( int x, int y );
	virtual ~EnemyShishimai( );
private:
	void act( );
private:
	int _anime_count;
};
