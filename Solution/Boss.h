#pragma once

#include "Enemy.h"
#include "smart_ptr.h"

class Boss : public Enemy {
public:
	Boss( int x, int y, int hp, int pow );
	virtual ~Boss();
public:
	virtual void attack( ) = 0;
private:
	virtual bool isOutSideScreen( CameraConstPtr camera ) const;
};

