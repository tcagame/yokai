#include "Cloud.h"

static const int CLOUD_CHIP_WAIT_TIME = 5;
static const int CLOUD_CHIP_PATTERN = 4;

Cloud::Cloud( int x, int y ) {
	_cloud_chip = CLOUD_CHIP::CLOUD_CHIP_0;
	_chip_count = 0;
	_x = x;
	_y = y;
}

Cloud::~Cloud( ) {
}

void Cloud::draw( CameraPtr camera ) {
}

void Cloud::update( ) {
	updateChip( );
	updatePos( );
}

void Cloud::updateChip( ) {
	_chip_count++;
	int add_chip = _chip_count / CLOUD_CHIP_WAIT_TIME;
	_chip_count %= CLOUD_CHIP_WAIT_TIME;
	_cloud_chip = CLOUD_CHIP( ( _cloud_chip + add_chip ) % ( CLOUD_CHIP_PATTERN - 1 ) );
}

void Cloud::updatePos( ) {

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