#pragma once
#include "Enemy.h"

class EnemyOneEyesSnake : public Enemy {
public:
	EnemyOneEyesSnake( int x, int y, bool dir_right = false );
	virtual ~EnemyOneEyesSnake( );
private:
	void act( );
	void actMove( );
	void updateChip( );
private:
	int _move_speed;
	int _before_x;
};