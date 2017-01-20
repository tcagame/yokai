#include "PsychicTarosuke.h"
#include "mathmatics.h"

static const int SPEED = 40;
static const int CHIP_SIZE = 128;

PsychicTarosuke::PsychicTarosuke( int x, int y, bool dir_right, int power ) :
Psychic( x, y ),
_dir_right( dir_right ),
_power( power ),
_outward( true ),
_motion_count( 0 ) {
}


PsychicTarosuke::~PsychicTarosuke( ) {
}

void PsychicTarosuke::act( ) {
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
		int idx = _power * 2 + _motion_count % 2;
		setChipUV( 3 + idx % 4, 3 + idx / 4 );
	} else {
		Vector pos( getX( ), getY( ) );
		Vector target( getTargetX( ), getTargetY( ) );
		Vector vec = target - pos;
		if ( vec.getLength( ) < SPEED ) {
			finish( );
		}
		vec = vec.normalize( ) * SPEED;
		setAccelX( ( int )vec.x );
		setAccelY( ( int )vec.y );
		setChipReverse( !_dir_right );
		setChipUV( 3 + _motion_count % 2, 0 );
		
		setChipFoot( ( int )( CHIP_SIZE / 2 + sin( 3.14159 * getX( ) / 300 ) * ( CHIP_SIZE / 4 ) ) );
	}
}

