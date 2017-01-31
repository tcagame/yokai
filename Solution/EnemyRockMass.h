#pragma once

#include "Enemy.h"
#include <array>

PTR( EnemyStoneMortgage );

class EnemyRockMass : public Enemy {
public:
	EnemyRockMass( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyRockMass( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
	double getOverlappedRadius( ) const;
private:
	static const int STONE_NUM = 10;
	int _count;
	bool _shrine_rope;
	std::array< EnemyStoneMortgagePtr, STONE_NUM > _stones;
};

