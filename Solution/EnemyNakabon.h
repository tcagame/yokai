#pragma once
#include "Enemy.h"

class EnemyNakabon : public Enemy {
public:
	EnemyNakabon( int x, int y );
	virtual ~EnemyNakabon( );
private:
	void act( );
private:
	int _act_count;
};

