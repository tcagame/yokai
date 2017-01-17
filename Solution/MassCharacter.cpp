#include "MassCharacter.h"
#include "define.h"
#include "Field.h"
#include "Camera.h"
#include "Cloud.h"

MassCharacter::MassCharacter( int x, int y ) {
	_x = x;
	_y = y;
	_accel_x = 0;
	_accel_y = 0;
}


MassCharacter::~MassCharacter( ) {
}

void MassCharacter::update( FieldPtr field ) {
	updateAccel( );
	updateDir( );
	move( field );
	updateChip( );
}

void MassCharacter::updateAccel( ) {
}

void MassCharacter::draw( ChipDrawerPtr chip_drawer, CameraConstPtr camera ) {
	bool reverse = ( _dir == DIR_RIGHT );

	chip_drawer->draw( _chip, _x - camera->getX( ) - CHIP_SIZE / 2, _y - camera->getY( ) - CHIP_SIZE + CHIP_FOOT_BLANK, reverse );
}

void MassCharacter::move( FieldPtr field ) {
	if ( _cloud ) {
		if ( !_cloud->isStanding( _x, 0, SCREEN_HEIGHT ) ||
			 _accel_y < 0 ) {
			_cloud = CloudConstPtr( );
		}
	}

    int src_x = _x;
    int src_y = _y;
	_x += _accel_x;
	_y += _accel_y;

	Field::Collision col = field->getCollision( src_x, src_y, _x, _y );

	if ( col.overlapped_x ) {
		_accel_x = 0;
		_x = col.adjust_x;
	}

	_standing = false;
	if ( col.overlapped_y ) {
		_accel_y = 0;
		_y = col.adjust_y;
		if ( col.cloud ) {
			_cloud = col.cloud;
		}
		_standing = true;
	}

	if ( _cloud ) {
		_y = _cloud->getY( ) - 1;
		_standing = true;
	}
}

void MassCharacter::manipulate( ) {
}

void MassCharacter::updateChip( ) {
}

void MassCharacter::updateDir( ) {
	if ( _accel_x > 0 ) {
		_dir = DIR_RIGHT;
	}
	if ( _accel_x < 0 ) {
		_dir = DIR_LEFT;
	}
}

int MassCharacter::getX( ) const {
	return _x;
}

int MassCharacter::getY( ) const {
	return _y;
}

void MassCharacter::setX( int x ) {
	_x = x;
}

void MassCharacter::setY( int y ) {
	_y = y;
}

void MassCharacter::adjustX( ) {
}

void MassCharacter::adjustY( ) {
}

void MassCharacter::setChip( ChipDrawer::CHIP chip ) {
	_chip = chip;
}

ChipDrawer::CHIP MassCharacter::getChip( ) {
	return _chip;
}

DIR MassCharacter::getDir( ) {
	return _dir;
}

void MassCharacter::fall( ) {
 	_accel_y += GRAVITY_POWER;
}

bool MassCharacter::isStanding( ) const {
	return _standing;
}
int MassCharacter::getAccelX( ) const {
	return _accel_x;
}

int MassCharacter::getAccelY( ) const {
	return _accel_y;
}

void MassCharacter::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void MassCharacter::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}
