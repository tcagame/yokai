#include "Character.h"


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
	debugChip( );
}

void Character::updateAccel( ) {
}

void Character::draw( ChipDrawerPtr chip_drawer ) {
	chip_drawer->draw( _chip, _x, _y );
}

void Character::moveVertical( ) {
	_x += _accel_x;
	_y += _accel_y;
}

void Character::debugChip( ) {
}

void Character::manipulate( ) {
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

void Character::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}
