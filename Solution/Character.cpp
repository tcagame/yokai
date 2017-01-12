#include "Character.h"
#include "define.h"
#include "Camera.h"

Character::Character( int x, int y ) {
	_x = x;
	_y = y;
	_accel_x = 0;
	_accel_y = 0;
}


Character::~Character( ) {
}

void Character::update( ) {
	updateAccel( );
	moveVertical( );
	updateChip( );
	debugChip( );
}

void Character::updateAccel( ) {
}

void Character::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( _dir == DIR_RIGHT );

	chip_drawer->draw( _chip, _x - CHIP_SIZE / 2 - camera->getX( ), _y - CHIP_SIZE, reverse );
}

void Character::moveVertical( ) {
	_x += _accel_x;
	_y += _accel_y;
}

void Character::debugChip( ) {
}

void Character::manipulate( ) {
}

void Character::updateChip( ) {
}

int Character::getX( ) const {
	return _x;
}
void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP Character::getChip( ) {
	return _chip;
}

void Character::fall( ) {
	_accel_y++;
}

void Character::setDir( DIR dir ) {
	_dir = dir;
}

void Character::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void Character::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}
