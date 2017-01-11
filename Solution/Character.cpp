#include "Character.h"


Character::Character( int x, int y ) {
	_x = x;
	_y = y;
	_acceleration_y = 0;
}


Character::~Character( ) {
}

void Character::update( ) {
	updateAcceleration( );
	moveVertical( );
	debugChip( );
}

void Character::updateAcceleration( ) {
}

void Character::draw( ChipDrawerPtr chip_drawer ) {
	chip_drawer->draw( _chip, _x, _y );
}

void Character::moveVertical( ) {
	_y += _acceleration_y;
}

void Character::debugChip( ) {
}


void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP Character::getChip( ) {
	return _chip;
}

void Character::fall( ) {
	_acceleration_y++;
}