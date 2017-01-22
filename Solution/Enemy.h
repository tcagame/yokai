#pragma once
#include "Character.h"
#include "EnemyStock.h"

PTR( EnemyStock );
PTR( Character );

class Enemy : public Character {
public:
	Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_size, int chip_foot, bool mass = true );
	virtual ~Enemy( );
public:
	bool isOverlapped( CharacterPtr target ) const;
	void damage( int pow );
	bool isFinished( ) const;
protected:
	EnemyStockPtr getEnemyStock( );
private:
	int _hp;
	EnemyStockPtr _enemy_stock;
};

