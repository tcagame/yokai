#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Momotaro );

class Status {
public:
	Status( );
	virtual ~Status( );
	void update( CameraConstPtr camera, MomotaroConstPtr momotaro );
	void draw( );
private:
	int _x;
};
