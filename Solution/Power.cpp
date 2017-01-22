#include "Power.h"

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
	_value -= pow;
	if ( _value < 0 ) {
		_value = 0;
	}
}

