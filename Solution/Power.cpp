#include "Power.h"

static const int MAX = 42;

Power::Power( ) :
_value( 3 ) {
}


Power::~Power( ) {
}

int Power::get( ) const {
	return _value;
}

void Power::decrease( int pow ) {
	_value -= pow;
	if ( _value < 0 ) {
		_value = 0;
	}
}

