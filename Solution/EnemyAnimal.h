#pragma once

#include "Enemy.h"

class EnemyAnimal : public Enemy {
public:
	EnemyAnimal( int x, int y, GRAPH graph );
	virtual ~EnemyAnimal( );
	virtual void damage( int pow );
	virtual Vector getOverlappedPos( ) const;
private:
	enum ACTION {
		ACTION_STAND,
		ACTION_YAWN,
		ACTION_GROOM,
		ACTION_FLOAT,
	};
private:
	void act( );
	void actOnStanding( );
	void actOnYawning( );
	void actOnGrooming( );
	void actOnFloating( );
private:
	ACTION _action;
	int _act_count;
	GRAPH _graph;
};