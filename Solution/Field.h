#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Map );
PTR( Cloud );

class Field {
public:
	Field( MapConstPtr map );
	virtual ~Field( );
	void update( CameraConstPtr camera );
	void draw( ) const;
	bool isChip( int x, int y ) const;
private:
	void drawBG( ) const;
	void drawChip( ) const;
private:
	const MapConstPtr _map;
	int _x;
	int _y;
	int _idx;
};

