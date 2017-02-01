#pragma once

#include "Enemy.h"
#include <array>

PTR( EnemyStock );
PTR( EnemyFire );

class EnemyBloodPondDemon : public Enemy {
public:
	EnemyBloodPondDemon( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyBloodPondDemon( );
private:
	void generate( );
	void act( );
	void updateChip( );
private:
	int _count;
	static const int FIRE_NUM = 20;
	std::array< EnemyFirePtr, FIRE_NUM > _fires;
	EnemyStockPtr _stock;
	bool _regist;
};

