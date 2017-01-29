#include "PsychicTarosuke.h"
#include "mathmatics.h"

static const int SPEED = 40;
static const int CHIP_SIZE = 128;

PsychicTarosuke::PsychicTarosuke( int x, int y, bool dir_right, int level ) :
Psychic( x, y ),
_dir_right( dir_right ),
_outward( true ),
_motion_count( 0 ),
_level( level ) {
	setPow( level + 1 );
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
			setPow( 0 );
		}
		setChipReverse( _dir_right );
		int idx = _level * 2 + _motion_count % 2;
		setChipGraph( GRAPH_PSYCHIC, idx % 8, 2 );
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
		setChipGraph( GRAPH_PSYCHIC, _motion_count % 2, 0 );
		
		setChipFoot( ( int )( CHIP_SIZE / 2 + sin( 3.14159 * getX( ) / 300 ) * ( CHIP_SIZE / 4 ) ) );
	}
}

void PsychicTarosuke::hit( bool killed ) {
	if ( getPow( ) == 1 || !killed ) {
		_outward = false;
		setPow( 0 );
	}
}

