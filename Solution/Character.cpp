#include "Character.h"
#include "Camera.h"
#include "ChipDrawer.h"

Character::Character( int x, int y ) :
_x( x ),
_y( y ) {
}


Character::~Character( ) {
}

int Character::getX( ) const {
	return _x;
}

int Character::getY( ) const {
	return _y;
}

ChipDrawer::CHIP Character::getChip( ) const {
	return _chip;
}

DIR Character::getDir( ) const {
	return _dir;
}

void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

void Character::setX( int x ) {
	_x = x;
}

void Character::setY( int y ) {
	_y = y;
}

void Character::setDir( DIR dir ) {
	_dir = dir;
}

void Character::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( getDir( ) == DIR_RIGHT );

	chip_drawer->draw( _chip, _x - camera->getX( ) - CHIP_SIZE / 2, _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK, reverse );
}

void Character::update( FieldPtr field ) {

}
