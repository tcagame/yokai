#include "Character.h"


Character::Character( int x, int y ) {
	_x = x;
	_y = y;
}


Character::~Character( ) {
}

void Character::update( ) {
	debugChip( );
}

void Character::draw( ChipDrawerPtr chip_drawer ) {
	chip_drawer->draw( _chip, _x, _y );
}

void Character::debugChip( ) {
}


void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP Character::getChip( ) {
	return _chip;
}