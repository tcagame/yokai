#include "Character.h"
#include "define.h"
#include "Field.h"
#include "Camera.h"
#include "Cloud.h"

Character::Character( int x, int y ) {
	_x = x;
	_y = y;
	_accel_x = 0;
	_accel_y = 0;
	_store_overlapped = false;
}


Character::~Character( ) {
}

void Character::update( FieldPtr field ) {
	updateAccel( );
	updateDir( );
	move( field );
	updateChip( );
	//debugChip( );
}

void Character::updateAccel( ) {
}

void Character::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( _dir == DIR_RIGHT );

	chip_drawer->draw( _chip, _x - camera->getX( ) - CHIP_SIZE / 2, _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK, reverse );
}

void Character::move( FieldPtr field ) {
    int dst_x = _x + _accel_x;
    int dst_y = _y + _accel_y;
	Field::Collision col = field->getCollision( _x, _y, dst_x, dst_y );

	if ( col.overlapped_x ) {
		_accel_x = 0;
		dst_x = col.adjust_x;
	}

	_standing = false;
	if ( col.overlapped_y ) {
		_accel_y = 0;
		dst_y = col.adjust_y;
		_standing = true;
	}

	_x = dst_x;
	_y = dst_y;
}

void Character::debugChip( ) {
}

void Character::manipulate( ) {
}

void Character::updateChip( ) {
}

void Character::updateDir( ) {
	if ( _accel_x > 0 ) {
		_dir = DIR_RIGHT;
	}
	if ( _accel_x < 0 ) {
		_dir = DIR_LEFT;
	}
}

int Character::getX( ) const {
	return _x;
}

int Character::getY( ) const {
	return _y;
}

void Character::setX( int x ) {
	_x = x;
}

void Character::setY( int y ) {
	_y = y;
}

void Character::adjustX( ) {
}

void Character::adjustY( ) {
}

void Character::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP Character::getChip( ) {
	return _chip;
}

DIR Character::getDir( ) {
	return _dir;
}

void Character::fall( ) {
 	_accel_y += GRAVITY_POWER;
}

bool Character::isStanding( ) const {
	return _standing;
}
int Character::getAccelX( ) const {
	return _accel_x;
}

int Character::getAccelY( ) const {
	return _accel_y;
}

void Character::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void Character::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}
