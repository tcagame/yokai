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
	virtual bool isOutSideScreen( CameraConstPtr camera ) const;
	bool isHead( ) const;
	virtual void steppedOn( );
protected:
	EnemyStockPtr getEnemyStock( );
	void setNoHead( );
private:
	const int _pow;
	int _hp;
	bool _head;
	EnemyStockPtr _enemy_stock;
};

