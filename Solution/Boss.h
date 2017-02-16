#pragma once

#include "Enemy.h"
#include "smart_ptr.h"

class Boss : public Enemy {
public:
	Boss( int x, int y, int chip_size, int hp, int pow );
	virtual ~Boss();
public:
	virtual void attack( ) = 0;
private:
	virtual Vector getOverlappedPos( ) const;
	virtual bool isOutSideScreen( CameraConstPtr camera ) const;
};

