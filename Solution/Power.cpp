#include "Power.h"
#include "Sound.h"
#include "Game.h"

static const int MAX = 42;

Power::Power( ) :
_value( MAX ) {
	GamePtr game = Game::getTask( );
	if ( game->isSuddendeath( ) ) {
		_value = 1;
	}
}


Power::~Power( ) {
}

int Power::get( ) const {
	return _value;
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
