#pragma once
#include "Enemy.h"

class EnemyNoNeckGhost : public Enemy {
public:
	EnemyNoNeckGhost( EnemyStockPtr stock, int x, int y );
	virtual~EnemyNoNeckGhost( );
private:
	void act( );
private:
	EnemyStockPtr _stock;
	int _accel;
	int _count;
};


