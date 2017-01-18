#include "PsychicNormal.h"
#include "mathmatics.h"

static const int SPEED = 24;

PsychicNormal::PsychicNormal( int x, int y, bool dir_right ) :
Psychic( x, y ),
_dir_right( dir_right ),
_outward( true ),
_motion_count( 0 ) {
}


PsychicNormal::~PsychicNormal( ) {
}

void PsychicNormal::act( ) {
	_motion_count++;

	if ( _outward ) {
		if ( _dir_right ) {
			setAccelX( SPEED );
		} else {
			setAccelX( -SPEED );
		}
		if ( getX( ) < getRange( ) || getX( ) > getRange( ) + SCREEN_WIDTH ) {
			_outward = false;
		}
		setChipReverse( _dir_right );
		setChipUV( _motion_count % 2, 3 );
	} else {
		setChipReverse( !_dir_right );
		setChipUV( _motion_count % 2, 3 );
	}
}

