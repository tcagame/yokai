#pragma once

#include "smart_ptr.h"
#include "mathmatics.h"

PTR( Camera );

class Item {
public:
	Item( int x, int y );
	virtual ~Item( );
public:
	bool update( const Vector& pos );
	void draw( CameraConstPtr camera ) const;
private:
	int _count;
	Vector _pos;
};

