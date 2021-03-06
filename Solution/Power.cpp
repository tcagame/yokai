#include "Power.h"
#include "Sound.h"
#include "Game.h"

static const int MAX = 42;

Power::Power( ) :
_value( MAX ) {
}


Power::~Power( ) {
}

int Power::get( ) const {
	return _value;
}

void Power::increase( int pow ) {
	_value += pow;
	if ( _value > MAX ) {
		_value = MAX;
	}
}

void Power::decrease( int pow ) {
	SoundPtr sound = Sound::getTask( );

	int n = _value;

	_value -= pow;
	if ( _value < 0 ) {
		_value = 0;
	}

	if ( _value <= 6 && n > 6 ) {
		sound->playSE( "yokai_se_02.wav", true );
	}	
}

void Power::reset( ) {
	_value = MAX;
}