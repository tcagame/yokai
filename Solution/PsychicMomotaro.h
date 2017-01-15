#pragma once
#include "smart_ptr.h"

PTR( Camera );

class PsychicMomotaro {
public:
	PsychicMomotaro( );
	virtual ~PsychicMomotaro( );
public:
	void update( );
	void draw( CameraConstPtr camera );
};

