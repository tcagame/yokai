#pragma once

#include "smart_ptr.h"
#include <list>

PTR( Psychic );
PTR( Camera );
PTR( Tarosuke );
PTR( Psychic );

class PsychicMgr {
public:
	PsychicMgr( );
	virtual ~PsychicMgr( );
public:
	void shoot( PsychicPtr psychic );
	void update( CameraConstPtr camera, TarosukeConstPtr tarosuke  );
	void draw( CameraConstPtr camera ) const;
private:
	std::list< PsychicPtr > _psychics;
};
