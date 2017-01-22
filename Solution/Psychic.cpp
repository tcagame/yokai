#include "Psychic.h"
#include "define.h"
#include "Drawer.h"
#include "Camera.h"

static const int MOVE_SPEED = 30;
static const int CHIP_SIZE = 128;

Psychic::Psychic( int x, int y ) :
Character( x, y, CHIP_SIZE, CHIP_SIZE / 2, false ) {
	_range_x = 0;
	_finished = false;
}

Psychic::~Psychic( ) {
}

void Psychic::setRange( int range_x, int target_x, int target_y ) {
	_range_x = range_x;
	_target_x = target_x;
	_target_y = target_y;
}

int Psychic::getRange( ) const {
	return _range_x;
}


int Psychic::getTargetX( ) const {
	return _target_x;
}

int Psychic::getTargetY( ) const {
	return _target_y;
}

void Psychic::finish( ) {
	_finished = true;
}

bool Psychic::isFinished( ) const {
	return _finished;
}


