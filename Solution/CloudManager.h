#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Cloud );
PTR( Camera );

class CloudManager {
public:
	CloudManager( );
	virtual ~CloudManager( );
	void draw( CameraPtr camera );
	void update( );
	CloudPtr getOverlappedCloud( int x, int y );
private:
	std::list< CloudPtr > _clouds;
};