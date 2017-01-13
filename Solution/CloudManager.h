#pragma once
#include "smart_ptr.h"
#include <list>

PTR( Cloud );
PTR( Camera );

class CloudManager {
public:
	enum CLOUD_CHIP {
		CLOUD_CHIP_0,
		CLOUD_CHIP_1,
		CLOUD_CHIP_2,
		CLOUD_CHIP_3
	};
public:
	CloudManager( );
	virtual ~CloudManager( );
	void draw( CameraPtr camera );
private:
	std::list< CloudPtr > _clouds;
};