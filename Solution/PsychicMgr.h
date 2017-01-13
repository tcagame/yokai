#pragma once

#include "smart_ptr.h"

PTR( Psychic );
PTR( Camera );

class PsychicMgr {
public:
	PsychicMgr( );
	virtual ~PsychicMgr( );
	void update( );
	void draw( CameraConstPtr camera );
	void shooting( int x, int y, bool right );
private:
	int _x;
	int _y;
	bool _right;
	PsychicPtr _psychic;
};
