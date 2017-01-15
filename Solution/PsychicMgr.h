#pragma once

#include "smart_ptr.h"

PTR( Psychic );
PTR( PsychicMomotaro );
PTR( Camera );

class PsychicMgr {
public:
	PsychicMgr( );
	virtual ~PsychicMgr( );
	void update( );
	void draw( CameraConstPtr camera );
	void shooting( int x, int y, bool right );
private:
	PsychicPtr _psychic;
	PsychicMomotaroPtr _psychic_momotaro;
};
