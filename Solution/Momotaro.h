#pragma once

#include "MassCharacter.h"

class Momotaro : public MassCharacter {
public:
	Momotaro( int x, int y );
	virtual ~Momotaro( );
	void draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera );
private:
	void updateAccel( );
	void manipulate( );
	void debugChip( );
	void adjustX( );
	void adjustY( );
};