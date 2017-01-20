#pragma once

#include "smart_ptr.h"
#include <list>

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
		CloudConstPtr cloud;
	};
	void update( CameraConstPtr camera );
	void draw( CameraConstPtr camera ) const;
	Collision getCollision( int src_x, int src_y, int dst_x, int dst_y ) const;
	unsigned int getEnemyData( );
	bool isChip( int x, int y ) const;
	bool isInWater( int x, int y ) const;
private:
	void drawBG( ) const;
	void drawChip( ) const;
	void drawClouds( CameraConstPtr camera ) const;
	void scroll( CameraConstPtr camera );
	void moveClouds( );
private:
	const MapConstPtr _map;
	int _scroll_x;
	int _scroll_y;
	int _idx;
	unsigned int _enemy_data;
	std::list< CloudPtr > _clouds;
};

