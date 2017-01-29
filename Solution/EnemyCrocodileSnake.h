#pragma once
#include "Enemy.h"

class EnemyCrocodileSnake : public Enemy {
public:
	EnemyCrocodileSnake( int x, int y );
	virtual ~EnemyCrocodileSnake( );
private:
	void act( );
	void actMove( );
	void updateChip( );
};