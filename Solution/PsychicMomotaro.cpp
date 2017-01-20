#include "PsychicMomotaro.h"
#include "Drawer.h"
#include "Camera.h"
#include "define.h"

PsychicMomotaro::PsychicMomotaro( int x, int y, int accel_x, int accel_y ) :
Psychic( x, y ) {
	_motion_count = rand( ) % 8;
	setAccelX( accel_x );
	setAccelY( accel_y );
}

PsychicMomotaro::~PsychicMomotaro( ) {
}

void PsychicMomotaro::act( ) {
	_motion_count++;

	if ( getX( ) < getRange( ) || getX( ) > getRange( ) + SCREEN_WIDTH ||
		 getY( ) < 0 || getY( ) > SCREEN_HEIGHT ) {
		finish( );
	}

	int idx = _motion_count;
	setChipUV( idx / 4 % 2, 3 );
}

