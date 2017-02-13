#pragma once

#include "smart_ptr.h"

PTR( Camera );

class ItemMgr {
public:
	ItemMgr( );
	virtual ~ItemMgr( );
public:
	void update( );
	void draw( CameraConstPtr camera ) const;
};

