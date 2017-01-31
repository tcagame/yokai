#pragma once
#include "Enemy.h"

class EnemyOneEyesSnake : public Enemy {
public:
	EnemyOneEyesSnake( int x, int y );
	virtual ~EnemyOneEyesSnake( );
private:
	void act( );
	void actMove( );
	void updateChip( );
};