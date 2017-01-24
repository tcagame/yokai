#include "Power.h"
#include "Sound.h"

static const int MAX = 42;

Power::Power( ) :
_value( MAX ) {
}


Power::~Power( ) {
}

int Power::get( ) const {
	return _value;
}

void Power::decrease( int pow ) {
	SoundPtr sound = Sound::getTask( );

	_value -= pow;
	if ( _value < 0 ) {
		_value = 0;
	}

	if ( _value <= 6 ) {
		sound->playBGM( "yokai_se_02.wav" );
	}

	
}


