#include "Psychic.h"
#include "define.h"
#include "Drawer.h"
#include "Camera.h"

static const int MOVE_SPEED = 30;
static const int CHIP_SIZE = 34 * 6;

Psychic::Psychic( int x, int y ) :
Character( x, y, GRAPH_EFFECT_0, CHIP_SIZE, CHIP_SIZE / 2, false ) {
	_range_x = 0;
}

Psychic::~Psychic( ) {
}

void Psychic::setRange( int x ) {
	_range_x = x;
}

int Psychic::getRange( ) const {
	return _range_x;
}

