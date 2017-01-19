#pragma once
#include "Character.h"
#include "EnemyStock.h"

PTR( EnemyStock );

class Enemy : public Character {
public:
	Enemy( EnemyStockPtr enemy_stock, int x, int y, int chip_graph, int chip_size, int enemy_foot, bool mass = true );
	virtual ~Enemy( );
protected:
	EnemyStockPtr getEnemyStock( );
private:
	EnemyStockPtr _enemy_stock;
};

