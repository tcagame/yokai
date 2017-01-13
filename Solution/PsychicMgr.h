#pragma once

#include "smart_ptr.h"
#include "Psychic.h"

PTR( Psychic );

class PsychicMgr {
public:
	PsychicMgr( );
	virtual ~PsychicMgr( );
	void update( );
	void draw( );
	void shooting( int x, int y, bool right );
private:
	int _x;
	int _y;
	bool _right;
	PsychicPtr _psychic;
};
