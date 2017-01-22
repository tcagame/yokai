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
	bool isOverlapped( CharacterPtr target );
	void damage( );
protected:
	EnemyStockPtr getEnemyStock( );
private:
	EnemyStockPtr _enemy_stock;
};

