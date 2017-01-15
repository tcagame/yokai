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
	bool isCloudExistence( int x, int y );
	CloudPtr getCloudPtr( ) const;
private:
	std::list< CloudPtr > _clouds;
	CloudPtr _cloud_overlapped;
};