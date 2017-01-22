#pragma once
#include "Character.h"
#include "EnemyStock.h"

PTR( EnemyStock );
PTR( Character );

class Enemy : public Character {
public:
	Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_size, int chip_foot, bool mass, int hp, int pow );
	virtual ~Enemy( );
public:
	bool isOverlapped( CharacterPtr target ) const;
	void damage( int pow );
	bool isFinished( ) const;
	int getPow( ) const;
protected:
	EnemyStockPtr getEnemyStock( );
private:
	const int _pow;
	int _hp;
	EnemyStockPtr _enemy_stock;
};

