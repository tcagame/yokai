#pragma once

#include "Enemy.h"

class EnemyStoneMortgage : public Enemy {
public:
	EnemyStoneMortgage( int x, int y, int type );
	virtual ~EnemyStoneMortgage( );
	void setMove( bool moveing );
	void back( );
private:
	void act( );
	void updateChip( );
	void actMove( );
private:
	int _count;
	int _start_x;
	int _start_y;
	int _type;
	bool _moveing;
};

