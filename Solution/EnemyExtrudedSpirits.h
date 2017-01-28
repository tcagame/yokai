#pragma once
#include "Enemy.h"

class EnemyExtrudedSpirits : public Enemy {
public:
	EnemyExtrudedSpirits( int x, int y );
	virtual ~EnemyExtrudedSpirits( );
private:
	void act( );
	void actMove( );
	void updateChip( );
	void appearing( );
private:
	int _count;
	bool _appears;
};
