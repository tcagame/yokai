#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Psychic );
PTR( Camera );

class PsychicMgr {
public:
	PsychicMgr( CameraConstPtr camera );
	virtual ~PsychicMgr( );
public:
	void shoot( int x, int y, bool reverse );
	void update( );
	void draw( CameraConstPtr camera );
private:
	CameraConstPtr _camera;
	std::list< PsychicPtr > _psychics;
};
