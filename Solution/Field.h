#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Map );
PTR( CloudManager );
PTR( Cloud );

class Field {
public:
	Field( MapConstPtr map, CloudManagerPtr cloud_mgr );
	virtual ~Field( );
	void update( CameraConstPtr camera );
	void draw( ) const;
	bool isChip( int x, int y ) const;
	bool isCloudExistence( int x, int y ) const;
	CloudPtr getCloudPtr( ) const;
private:
	void drawBG( ) const;
	void drawChip( ) const;
private:
	const MapConstPtr _map;
	const CloudManagerPtr _cloud_mgr;
	int _x;
	int _y;
	int _idx;
};

