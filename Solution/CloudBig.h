#pragma once
#include "Cloud.h"

class CloudBig : public Cloud {
public:
	CloudBig( int x, int y );
	virtual ~CloudBig( );
	void draw( CameraPtr Camera );
};

