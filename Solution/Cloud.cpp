#include "Cloud.h"

static const int CLOUD_CHIP_WAIT_TIME = 5;
static const int CLOUD_CHIP_PATTERN = 4;
static const int CLOUD_MOVE_SPEED = 4;
static const int MAX_TURN_COUNT = 40;

Cloud::Cloud( int x, int y ) {
	_cloud_chip = CLOUD_CHIP::CLOUD_CHIP_0;
	_x = x;
	_y = y;
	_accel = CLOUD_MOVE_SPEED;
	_chip_count = 0;
	_turn_count = 0;
}

Cloud::~Cloud( ) {
}

void Cloud::draw( CameraPtr camera ) {
}

void Cloud::update( ) {
	updateChip( );
	updateAccel( );
	moveVertical( );
}

void Cloud::updateChip( ) {
	_chip_count++;
	int add_chip = _chip_count / CLOUD_CHIP_WAIT_TIME;
	_chip_count %= CLOUD_CHIP_WAIT_TIME;
	_cloud_chip = CLOUD_CHIP( ( _cloud_chip + add_chip ) % ( CLOUD_CHIP_PATTERN - 1 ) );
}

void Cloud::updateAccel( ) {
	_turn_count++;
	_turn_count %= MAX_TURN_COUNT;
	if ( _turn_count == 0 ) {
		_accel *= -1;
	}
}

void Cloud::moveVertical( ) {
	_y += _accel;
}

int Cloud::getX( ) {
	return _x;
}

int Cloud::getY( ) {
	return _y;
}

Cloud::CLOUD_CHIP Cloud::getChip( ) {
	return _cloud_chip;
}