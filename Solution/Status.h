#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Momotaro );
PTR( Power );

class Status {
public:
	Status( PowerConstPtr power  );
	virtual ~Status( );
public:
	void update( );
	void draw( );
private:
	PowerConstPtr _power;
};
