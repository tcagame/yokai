#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Cloud );
PTR( Camera );
PTR( Map );

class CloudMgr {
public:
	CloudMgr( );
	virtual ~CloudMgr( );
public:
	void update( );
	void draw( CameraConstPtr camera );
	void add( CloudPtr cloud );
	CloudPtr getOnStanding( int src_x, int src_y, int dst_y );
private:
	std::list< CloudPtr > _clouds;
};

