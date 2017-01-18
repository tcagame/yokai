#pragma once

#include "Psychic.h"

class PsychicNormal : public Psychic {
public:
	PsychicNormal( int x, int y, bool reverse );
	virtual ~PsychicNormal( );
private:
	void act( );
private:
	bool _dir_right;
	bool _outward;
	int _motion_count;
};

