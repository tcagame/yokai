#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Cloud );
PTR( Camera )

class CloudMgr {
public:
	CloudMgr( );
	virtual ~CloudMgr( );
public:
	void update( );
	void draw( CameraConstPtr camera );
	CloudPtr getOnStanding( int src_x, int src_y, int dst_y );
private:
	std::list< CloudPtr > _clouds;
};

