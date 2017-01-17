#include "MassCharacter.h"
#include "define.h"
#include "Field.h"
#include "Camera.h"
#include "Cloud.h"

MassCharacter::MassCharacter( int x, int y ) :
Character( x, y ) {
	_accel_x = 0;
	_accel_y = 0;
}


MassCharacter::~MassCharacter( ) {
}

void MassCharacter::update( FieldPtr field ) {
	fall( );
	updateAccel( );
	updateDir( );
	move( field );
	updateChip( );
}

void MassCharacter::updateAccel( ) {
}

void MassCharacter::move( FieldPtr field ) {
	if ( _cloud ) {
		if ( !_cloud->isStanding( getX( ), 0, SCREEN_HEIGHT ) ||
			 _accel_y < 0 ) {
			_cloud = CloudConstPtr( );
		}
	}

    int src_x = getX( );
    int src_y = getY( );
	int dst_x = src_x + _accel_x;
	int dst_y = src_y + _accel_y;

	Field::Collision col = field->getCollision( src_x, src_y, dst_x, dst_y );

	if ( col.overlapped_x ) {
		_accel_x = 0;
		dst_x = col.adjust_x;
	}

	_standing = false;
	if ( col.overlapped_y ) {
		_accel_y = 0;
		dst_y = col.adjust_y;
		if ( col.cloud ) {
			_cloud = col.cloud;
		}
		_standing = true;
	}

	if ( _cloud ) {
		dst_y = _cloud->getY( ) - 1;
		_standing = true;
	}

	setX( dst_x );
	setX( dst_y );
}

void MassCharacter::manipulate( ) {
}

void MassCharacter::updateChip( ) {
}

void MassCharacter::updateDir( ) {
	if ( _accel_x > 0 ) {
		setDir( DIR_RIGHT );
	}
	if ( _accel_x < 0 ) {
		setDir( DIR_LEFT );
	}
}

void MassCharacter::adjustX( ) {
}

void MassCharacter::adjustY( ) {
}

void MassCharacter::fall( ) {
	_accel_y += GRAVITY_POWER;
}

bool MassCharacter::isStanding( ) const {
	return _standing;
}

void MassCharacter::setAccelX( int accel_x ) {
	_accel_x = accel_x;
}

void MassCharacter::setAccelY( int accel_y ) {
	_accel_y = accel_y;
}
