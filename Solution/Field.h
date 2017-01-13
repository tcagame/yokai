#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Map );

class Field {
public:
	Field( MapConstPtr map );
	virtual ~Field( );
	void update( CameraConstPtr camera );
	void draw( ) const;
private:
	void drawBG( ) const;
	void drawChip( ) const;
private:
	const MapConstPtr _map;
	int _x;
	int _y;
	int _idx;
};

