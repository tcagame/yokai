#pragma once
#include "Character.h"
#include "EnemyStock.h"

PTR( EnemyStock );
PTR( Character );

class Enemy : public Character {
public:
	Enemy( int x, int y, int chip_size, int chip_foot, bool mass, int hp, int pow );
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
	void setNoHead( );
private:
	const int _pow;
	int _hp;
	bool _head;
};

