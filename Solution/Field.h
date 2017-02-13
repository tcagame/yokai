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
PTR( EnemyStock );
PTR( ItemMgr );

class Field {
public:
	Field( MapConstPtr map, EnemyStockPtr stock );
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
	bool isChip( int x, int y ) const;
	bool isBlockChip( int x, int y ) const;
	FLOOR getFloor( int x, int y ) const;
	Vector getStatusMarkerPos( int x ) const;
	int getLimitX( ) const;
private:
	void drawFarBG( CameraConstPtr camera ) const;
	void drawBG( ) const;
	void drawChip( ) const;
	void scroll( CameraConstPtr camera );
	void initMark( );
private:
	const MapConstPtr _map;
	const EnemyStockPtr _stock;
	int _scroll_x;
	int _scroll_y;
	int _idx;
	int _create_idx;
	CloudMgrPtr _cloud_mgr;
	ItemMgrPtr _item_mgr;
	std::vector< Vector > _markers; 
};

