#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Camera );
PTR( Item );
PTR( Tarosuke );

class ItemMgr {
public:
	ItemMgr( );
	virtual ~ItemMgr( );
public:
	void update( CameraConstPtr camera, TarosukePtr tarosuke );
	void draw( CameraConstPtr camera ) const;
	void add( ItemPtr item );
private:
	std::list< ItemPtr > _items;
};

