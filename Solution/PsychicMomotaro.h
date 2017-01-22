#pragma once

#include "smart_ptr.h"
#include "Psychic.h"

class PsychicMomotaro : public Psychic {
public:
	PsychicMomotaro( int x, int y, int accel_x, int accel_y );
	virtual ~PsychicMomotaro( );
private:
	void act( );
	void hit( );
private:
	int _motion_count;
};

