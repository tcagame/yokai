#pragma once
#include "Cloud.h"

class CloudSmall : public Cloud {
public:
	CloudSmall( int x, int y );
	virtual ~CloudSmall( );
	void draw( CameraPtr camera );
};
