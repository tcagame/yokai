#pragma once

#include "Enemy.h"

class EnemyStoneMortgage : public Enemy {
public:
	EnemyStoneMortgage( int x, int y );
	virtual ~EnemyStoneMortgage( );
	void setMove( bool moveing );
	void back( );
private:
	void act( );
	void updateChip( );
	void actMove( );
	void actStop( );
private:
	int _count;
	int _start_x;
	int _start_y;
	bool _moveing;
	bool _back;
};

