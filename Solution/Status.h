#pragma once

#include "smart_ptr.h"

PTR( Camera );
PTR( Momotaro );

class Status {
public:
	Status( );
	virtual ~Status( );
public:
	void update( );
	void draw( );
};
