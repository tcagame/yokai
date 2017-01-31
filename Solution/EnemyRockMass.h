#pragma once

#include "Enemy.h"
#include <array>

PTR( EnemyStoneMortgage );
PTR( EnemyATField );
PTR( EnemyStock );

class EnemyRockMass : public Enemy {
public:
	EnemyRockMass( EnemyStockPtr stock, int x, int y );
	virtual ~EnemyRockMass( );
private:
	void act( );
	void drawOverlapped( CameraConstPtr camera ) const;
	void damage( int pow );
private:
	static const int STONE_NUM = 10;
	EnemyStockPtr _stock;
	bool _regist;
	int _count;
	bool _shrine_rope;
	bool _invisible;
	std::array< EnemyStoneMortgagePtr, STONE_NUM > _stones;
	EnemyATFieldPtr _a_t_field;
};

