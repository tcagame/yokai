#pragma once

#include "smart_ptr.h"
#include "define.h"
#include "mathmatics.h"
#include <list>
#include <vector>

PTR( Camera );
PTR( Map );
PTR( Cloud );
PTR( CloudMgr );

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
	void drawCover( ) const;
	Collision getCollision( int src_x, int src_y, int dst_x, int dst_y ) const;
	unsigned long long getEnemyData( );
	bool isChip( int x, int y ) const;
	bool isBlockChip( int x, int y ) const;
	FLOOR getFloor( int x, int y ) const;
	Vector getStatusMarkerPos( int x ) const;
private:
	void drawBG( ) const;
	void drawChip( ) const;
	void drawClouds( CameraConstPtr camera ) const;
	void scroll( CameraConstPtr camera );
	void moveClouds( );
	void initMark( );
private:
	const MapConstPtr _map;
	int _scroll_x;
	int _scroll_y;
	int _idx;
	int _create_idx;
	unsigned long long _enemy_data;
	std::list< CloudPtr > _clouds;
	CloudMgrPtr _cloud_mgr;
	bool _debug_mapchip;
	std::vector< Vector > _markers; 
};

