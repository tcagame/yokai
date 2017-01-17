#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Map );
PTR( Cloud );

class Field {
public:
	Field( MapConstPtr map );
	virtual ~Field( );
public:
	struct Collision {
		bool overlapped_x;
		bool overlapped_y;
		int adjust_x;
		int adjust_y;
	};
	void update( CameraConstPtr camera );
	void draw( ) const;
	Collision getCollision( int src_x, int src_y, int dst_x, int dst_y ) const;
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

